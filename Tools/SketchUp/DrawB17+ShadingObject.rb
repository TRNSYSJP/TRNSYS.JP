# First we pull in the standard API hooks.
require 'sketchup.rb'

# Show the Ruby Console at startup so we can
# see any programming errors we may make.
#Sketchup.send_action "showRubyPanel:"

# Vertex class
class Vertex
  def initialize(no, x, y, z)
    @no = no
  #座標値を[m]で保存
    @x = x.to_f.m
    @y = y.to_f.m
    @z = z.to_f.m
=begin
    @x = x.to_f
    @y = y.to_f
    @z = z.to_f
=end
   
  end

  def getNo
    @no
  end
  
  def getX
    @x
  end
  
  def getY
    @y
  end

  def getZ
    @z
  end  
end
# Wall/Window class
class Surface
  def initialize(no, *vertex)
    @no = no
    @vertices =  Array.new(vertex)
  end
  def getVertices
     @vertices
  end

end
# Zone　class
class Zone
  def initialize(id)
    @id = id
	@surfaces = []
  end
  def getID
	@id
  end
  def getSurfaces
     @surfaces
  end

end



# Add a menu item to launch our plugin.
UI.menu("PlugIns").add_item("Draw B17 and Shading Objects") {
	
	#Chose and parse a bui(*.b17)  file.
	#-------------------------------------------------------------------------------
	chosen_bui = UI.openpanel "Open bui file", "", "*.b17"
	puts chosen_bui
	if chosen_bui == nil 
	exit
	end

	# BuildingGeometoryセクションの判定フラグ
	geoSection = 0

	#配列の初期化
	vertices=[]
	vertices.push(Vertex.new(0,0,0,0)) #ダミーのデータを挿入する
	zones=[]
	zone=nil
	
	# Zone/Wall/Windowの処理
	#----------------------------------------------------------------------------------------------------
	# Open the chosen bui file
	f = open(chosen_bui)
	while line = f.gets
		if (geoSection == 1) && (line.index("_EXTENSION_BuildingGeometry_END_") != nil)
			geoSection=0
		end
	  
		#BuildingGeometryを処理する
		if geoSection == 1
			#　vertexの処理
			if line.index("vertex")  != nil
			  vals = line.split
			  vertex = Vertex.new(vals[1], vals[2], vals[3], vals[4])
			  vertices.push(vertex)
			end 
			
			#　zoneの処理
			if line.index("zone") != nil
			  vals = line.split
			  zone = Zone.new(vals[1]) #idを指定してZoneインスタンスを生成
			  zones.push(zone)
			end
			  
			# wall,windowはSurfaceクラスとして処理
			if line.index("wall")|| line.index("window")
			  vals = line.split
			  surface = Surface.new(vals[1], vals[2..vals.size-1]) # SurfNoと頂点の番号へ分ける
			  zone.getSurfaces.push(surface)
			end    
		end
	  
	  # セクションの開始位置を通り過ぎたので、処理用にフラグをセットする
	  if line.index("_EXTENSION_BuildingGeometry_START_") != nil
		geoSection=1
	  end
	end
	
	f.close

	# Shading Objectの読み込み処理
	#----------------------------------------------------------------------------------------------------
	# 初期化
	geoSection=0
	zone = Zone.new("ShadingObjects") # Shading Objectを一括して一つのZoneとして扱う
	zones.push(zone)
	# Open the chosen bui file
	f = open(chosen_bui)
	while line = f.gets
		if (geoSection == 1) && (line.index("_EXTENSION_ExternalShadingGeometry_END_") != nil)
			geoSection=0
		end
	  
		#BuildingGeometryを処理する
		if geoSection == 1
			#　vertexの処理
			if line.index("vertex")  != nil
			  vals = line.split
			  vertex = Vertex.new(vals[1], vals[2], vals[3], vals[4])
			  vertices.push(vertex)
			end 
  
			# shaderをSurfaceクラスとして処理
			if line.index("shader")
			  vals = line.split
			  surface = Surface.new(vals[1], vals[2..vals.size-1]) # SurfNoと頂点の番号へ分ける
			  zone.getSurfaces.push(surface)
			end    
		end
	  
	  # セクションの開始位置を通り過ぎたので、処理用にフラグをセットする
	  if line.index("_EXTENSION_ExternalShadingGeometry_START_") != nil
		geoSection=1
	  end
	end
	
	f.close
	
	#Draw all of Zones, Walls, Windows and Shading Objects in SketchUp
	#-------------------------------------------------------------------------------

	# Get "handles" to our model and the Entities collection it contains.
	model = Sketchup.active_model
	entities = model.entities

	zones.each{|zone|
	 # Add a group to the model.
		group = entities.add_group
		group.name = zone.getID
		#p group.name

		surfaces = zone.getSurfaces
		surfaces.each{|surface|
			indices =surface.getVertices
			pts = []
		 
			indices[0].each{|index| # Loop for vertex
			  #puts vertices[index.to_i].getX,vertices[index.to_i].getY,vertices[index.to_i].getZ 
				v = vertices[index.to_i]
				pt = Array.new([v.getX, v.getY, v.getZ])
				pts.push(pt)
			}
			#Add a face to the group
			newface = group.entities.add_face pts
		}
	}
}
