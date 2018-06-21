## リードミッ！φ(ﾟvﾟ*)♪

- BlenderのキューブをArduinoにつなげたスイッチ(将来的にロータリーエンコーダ使用予定)で,遠隔操作するために作ったコードを保管するためのもの

## 起動用(rokuro_over以外)
 - 下はターミナルからblenderを開いて、エラー等をターミナルに出すことができる
 - `/Applications/Blender/blender.app/Contents/MacOS/blender`


### 参考サイト
 - http://nn-hokuson.hatenablog.com/entry/2017/03/26/102145
 - 文字コード削除→ https://qiita.com/moritama1515/items/bc37c3d7d5280c877950

## 以下,[こちら](https://github.com/youk720/BlenderRokuro/blob/master/README.md)と同様の内容を記載

[元リポジトリ](https://github.com/satoyuichi/BlenderRokuro)

# BlenderRokuro rotary_encoder compatible version
　メッシュオブジェクトをロータリーエンコーダで回転させ続けます。ろくろで作る器のような形状を作る時に便利です。

## 使用条件
* Blender 2.78 以上

## 機能
* 回転軸の選択
* 回転方向の選択
* 一周の分割数の選択
* 時間のステップ数の選択

## 使い方

### arduino側
1. rotary_blenderのフォルダ内のinoファイルをarduinoに書き込む
2. a相(右回り)はD2,b相(左回り)はD3ピンに接続
3. D6,7ピンはLEDをさすピンで必要なければつけなくても良い(6は左に回したときに,7は右に回したときに光る)
#### ⚠️注意⚠️
 - LED刺すときには,故障防止のため,"必ず" 直前に抵抗を挟んでください
 - arduinoのシリアルポートは機材によって異なります。それぞれ各自のものに合わせて修正してください
      1. コマンドプロンプトに`ls /dev/ *`を実行.windowsの場合は[こちらを](https://qiita.com/Acqua_Alta/items/9f19afddc6db1e4d4286#pc--arduino%E3%82%B7%E3%83%AA%E3%82%A2%E3%83%AB%E9%80%9A%E4%BF%A1)
    2.  arduinoのツールタブにある`シリアルポート`のリンクと一致するものを[blender_rokuro_over.py](https://github.com/youk720/BlenderRokuro/blob/master/blender_rokuro_over.py)126行目の`/dev....`の中に入れて置き換える
 ![1](/photo/image_1.PNG  =317x127)
 ![2](/photo/image_2.PNG  =251x117)
 ![3](/photo/image_3.PNG  =207x119)

### blender側
1. アドオンをインストールして有効にします
2. メッシュを選択してスカルプトモードにします
3. ツールシェルフに "Rokuro" パネルが開きます
4. お好みの設定をして "Enable Rokuro" ボタンを押してから、ロータリーエンコーダを操作すると回る
5. x,y,z軸のチェックボックスをonにしているものが
6. "Disable Rokuro" ボタンを押して終了します←(今の所ロータリーエンコーダ回しながらでないと操作できない)

　~~Start, End 値で一周を何分割するか、Step 値で１フレーム当たりいくつ進めるかが決まります。~~

(オマケとしてテクスチャペイントモードでも動作します)

## 上手く作るコツ
* Stroke Method で Airbrush を有効にする
* Symmetry / Lock で Mirror を切る
* Brush で Front Faces Only を有効にする
* 厚みは後で Solidify などでつける
* あまり早く回さない

## ライセンス
[MIT ライセンス](http://takuro.mit-license.org/)

## 既知のバグ
* 回転前の Rotation 値が戻らないことがあります
* "Enable Rokuro"クリック後,シリアル通信(?)の関係でロータリーエンコーダ操作しながらでないと、停止やチェックボックスなどの操作ができない
* ロータリーエンコーダの構造上,arduinoで読み取りに誤差があり,そのためblenderやLEDに本来光らない・反応しない側に入ることが多い

## 参考サイト
- http://nn-hokuson.hatenablog.com/entry/2017/03/26/102145
- 文字コード削除→ https://qiita.com/moritama1515/items/bc37c3d7d5280c877950
- https://qiita.com/Acqua_Alta/items/9f19afddc6db1e4d4286


### 製作者
- 元データ:[Yuichi sato様](https://github.com/satoyuichi)
- ロータリーエンコーダ操作対応作成:[youk720(自分)](https://github.com/youk720)
