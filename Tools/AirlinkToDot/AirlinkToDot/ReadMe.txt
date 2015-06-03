2015/6/3
Graphvizを内部で起動、イメージを生成する処理へ変更した。

GraphViz-C-Sharp-Wrapper（https://github.com/JamieDixon/GraphViz-C-Sharp-Wrapper）を使用してGraphviz/Dotの処理を実装している。


※実行環境としてGraphvizが必須。
以下の手順に従って設定を行ってください。

1.Graphvizのインストール
Graphvizのオフィシャルサイトからインストーラーをダウンロード、インストールを行う。
http://www.graphviz.org/Download_windows.php

2.Binフォルダのファイルをコピーする
Graphvizの実行に必要なファイル一式をコピーする。
実行フォルダ（例：\AirlinkToDot\bin\Debug/Release）へ"GraphViz"という名前でフォルダを作成する。
このフォルダへ、Graphviz\binフォルダ(C:\Program Files (x86)\Graphviz2.38\bin)のすべてのファイルをコピーする。



