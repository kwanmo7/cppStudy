# XML シリアル化 & デシリアル化

## プロジェクト概要
このプロジェクトは、C++を使用してXMLデータのシリアル化（Serialize）およびデシリアル化（Deserialize）を行う機能を提供します。映画データをXML形式に変換してファイルに保存し、再びXMLファイルからデータを読み込んで復元することができます。データ構造は`movie_list`という映画データのリストを使用し、PugiXMLライブラリを活用してXML処理を実装しています。

---

## 主なファイル
### 1. **`main.cpp`**
- プロジェクトのエントリーポイント。
- 映画データを初期化し、シリアル化およびデシリアル化の機能をテストする役割を持っています。
- **主な機能**:
  - `movie_list`データを生成。
  - `serialize()`を呼び出してXMLファイルを生成。
  - `deserialize()`を呼び出してXMLファイルからデータを復元。
  - テストのために`assert`を使用して結果を検証。
  - `select_with_xpath()`を呼び出しXPathを利用しXMLデータを選択。

### 2. **`xml_serialize.cpp`**
- `movie_list`データをXML形式に変換し、ファイルに保存する機能を実装します。
- **主な関数**:
  - `serialize(movie_list const &movies, string_view filepath)`:
    - 映画データをXMLファイルに保存します。

### 3. **`xml_deserialize.cpp`**
- XMLファイルを読み取り、データを解析して`movie_list`構造に復元する機能を担当します。
- **主な関数**:
  - `deserialize(string_view filepath)`:
    - XMLファイルを読み込んでデータを復元します。

### 4. **`xpath_selector.cpp`**
- XPathを使用してXMLデータを検索および選択する機能を提供します。
- **主な関数**:
  - `select_with_xpath(const std::string &file)`:
    - XMLファイルをロードし、XPathクエリを実行して結果を出力します。
    - **使用例**:
      - `/movies/movie[@year>1995]`: 年が1995より大きい`<movie>`ノードを選択。
      - `movies/movie/cast/role[last()]`: 各`<movie>`ノードのキャストの最後の`<role>`ノードを選択。

### 5. **`movie_data.h`**
- 映画データの構造を定義するヘッダーファイル。
- **構造体**:
  - `casting_role`: 俳優と役名の情報を含む。
  - `movie`: 映画のID、タイトル、公開年、上映時間、出演者、監督、脚本家情報を含む。
  - `movie_list`: 映画のリストを`std::vector`で保存。

---

## 使用方法
### 1. **シリアル化**
1. `main.cpp`で`movie_list`データを初期化します。
2. `serialize()`関数を呼び出してデータをXMLファイルに保存します。
3. 結果ファイル（`movies.xml`）がプロジェクトディレクトリ内に作成されます。

### 2. **デシリアル化**
1. XMLファイル（`movies.xml`）を読み取り、`deserialize()`関数でデータを復元します。
2. 復元されたデータを確認または編集できます。

### 3. **XPathデータ選択**
`xpath_selector.cpp`ファイルで提供される`select_with_xpath()`関数を呼び出してXMLデータを選択および処理できます。

---

## 開発環境
- **IDE**: Visual Studio Code (VS Code)
- **使用したC++バージョン**: C++17
- **コンパイラ**: g++ 8.1.0 (x86_64-posix-sjlj-rev0, MinGW-W64)

---

## 依存関係
- **PugiXML**: XML処理用の軽量ライブラリ。
  - [PugiXML GitHubページ](https://github.com/zeux/pugixml)

---

## ビルドと実行
### 1. **コンパイル**
ターミナルで以下のコマンドを実行してください:
```bash
g++ -std=c++17 -g src/main.cpp src/xml_serialize.cpp src/xml_deserialize.cpp src/xpath_selector.cpp third_party/pugixml/pugixml.cpp -o main.exe