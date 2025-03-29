# JSON シリアル化とデシリアライズ

## プロジェクト概要
このプロジェクトでは、映画データをJSON形式にシリアル化(Serialize)し、JSONファイルからデータを読み取ってデシリアライズ(Deserialize)する機能を実装します。映画データには、映画ID、タイトル、公開年、上映時間、キャスト、監督、作家情報が含まれます。

---

## 主なファイル

### **`movie_data.h`**
- 映画データを定義するヘッダーファイルです。
- 主なデータ構造:
  - `casting_role`: 俳優と役名情報を格納。
  - `movie`: 映画のID、タイトル、公開年、上映時間、キャスト、監督、作家情報を含む。
  - `movie_list`: 映画リストを格納する`std::vector`構造。

### **`json_serialize.cpp`**
- 映画データをJSONに変換し、ファイルに保存する機能を提供します。
- 主な関数:
  - `to_json`: `casting_role`および`movie`データをJSONオブジェクトに変換。
  - `serialize`: `movie_list`データをJSONファイルにシリアル化。

### **`json_deserialize.cpp`**
- JSONファイルからデータを読み取り、`movie_list`構造に復元する機能を提供します。
- 主な関数:
  - `parse_movie`: JSONオブジェクトを`movie`オブジェクトに変換。
  - `deserialize`: JSONファイルを読み込み、データを`movie_list`にデシリアライズ。

### **`main.cpp`**
- 全体の機能をテストするための実行ファイルです。
- 主な作業:
  1. 映画データを初期化。
  2. `serialize`でJSONファイルに保存。
  3. `deserialize`でJSONファイルからデータを復元。
  4. データの一貫性を検証し、結果を出力。

---

## 使用方法

### **コンパイル**
1. 以下のコマンドでプロジェクトをコンパイルしてください。
   ```bash
   g++ -std=c++17 -o main main.cpp