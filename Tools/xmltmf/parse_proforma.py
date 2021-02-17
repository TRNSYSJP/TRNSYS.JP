# Example of saving Proformas
# Create XML Proformas with "Collector area" of 2,4,6,8 square meters.
# author     Yuichi Yasuda @ quattro corporate design
# copyright  2021 quattro corporate design. All right reserved.

import xml.etree.ElementTree as ET
tree = ET.parse(r'C:\TRNSYS18\Studio\Proformas\MyComponents\MyType1a.xmltmf')
root = tree.getroot()

nodes = root.findall("./variables/variable")    
for node in nodes:
    if node.find('name').text == 'Collector area':
        #集熱面積のnodeを探して新しい集熱面積を設定する
        def_value = node.find('default')
        # 集熱面積2,4,6,8㎡のプロフォルマを作成する
        for area in range(2, 10, 2):        
            def_value.text=str(area)
            fname = f'MyType1a_{area}m2.xmltmf'
            xmltmf = r'C:\TRNSYS18\Studio\Proformas\MyComponents'+'\\' + fname
            tree.write(xmltmf)