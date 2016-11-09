2016/11/07

このフォルダにはTRNSYSカスタムコンポーネントのソースコードと関連するファイルが納められています。

以下、FlowDesginerに関連したコンポーネントのサンプルの説明です。

・Type219Controller
FlowDesigerとの連携デモで使用した簡易エアコンモデル。
(デモ用に簡単な式で処理しています。実際のエアコンとは動作が異なります。）

・Type220SensorData
FlowDesingerからセンサーデータを取得するコンポーネント。

・Type221ControlData
TRNSYSのデータをFlowDesginerのコントロールデータとして書き出し処理を行うコンポーネント。

※各コンポーネントのParameters/Inputs/Outputsの詳細はPDF形式のドキュメントを参照下さい。


【利用方法】
ご利用には各コンポーネントに対応するProforma、DLLをTRNSYSのインストールフォルダへのコピーが必要です。

・Proforma
\TRNSYS.JP\TRNSYS17.1\Studio\Proformas\FlowDesigner フォルダをTRNSYSのインストールフォルダ（C:\TRNSYS17\Studio\Proformas\）へコピーしてご利用下さい。

・DLL
\TRNSYS.JP\TRNSYS17.1\UserLib\ReleaseDLLs フォルダに含まれるDLL（下記）をTRNSYSのフォルダ（C:\TRNSYS17\UserLib\ReleaseDLLs\）へコピーして下さい。
Type219Controller.dll
Type220SensorData.dll
Type221ControlData.dll

・Descrips.datの編集
＜TRNSYSのインストールフォルダ＞\Exe\Descrips.dat をメモ帳で開き、最後の行へ、以下の1行を追加してください。

221 !MyComponent: Type221


※詳しくは"\TRNSYS.JP\TRNSYS17.1\Compilers\IvfCXE2011\ビルド方法 - FlowDesinger221.docx"を参照


以上で設定は終了です。Simulation Studio を起動した状態であれば、いったん終了して起動しなおしてください。（コピーしたファイルが読み込まれます）



【動作環境】
以下の環境で動作を確認しています。

TRNSYS17.01.0028
Intel Parallel Stuido XE2013(Intel Visual Fortran)

