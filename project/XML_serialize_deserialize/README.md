# XML Serialize & Deserialize

## 프로젝트 개요
이 프로젝트는 C++ 기반으로 XML 데이터를 직렬화(Serialize)하고, 디시리얼라이즈(Deserialize)하는 기능을 제공합니다. 영화 데이터를 XML로 변환하여 파일에 저장하고, 다시 XML 파일로부터 데이터를 읽어와 복원하는 기능을 구현합니다. 데이터 구조는 `movie_list`라는 영화 데이터 목록을 사용하며, PugiXML 라이브러리를 활용하여 XML 처리 작업을 수행합니다.

---

## 주요 파일
### 1. **`main.cpp`**
- 프로젝트의 엔트리 포인트.
- 영화 데이터를 초기화하고, 직렬화 및 디시리얼라이즈 기능을 테스트하는 역할을 담당합니다.
- **주요 기능**:
  - `movie_list` 데이터를 생성.
  - `serialize()`를 호출해 XML 파일 생성.
  - `deserialize()`를 호출해 XML 파일에서 데이터를 복원.
  - 테스트를 위해 `assert`로 결과 검증.
  - `select_with_xpath()`를 호출해 XPath를 사용하여 XML 데이터를 선택

### 2. **`xml_serialize.cpp`**
- `movie_list` 데이터를 XML 형식으로 변환하고 파일로 저장하는 기능을 구현합니다.
- **주요 함수**:
  - `serialize(movie_list const &movies, string_view filepath)`:
    - 영화 데이터를 XML 파일로 저장합니다.

### 3. **`xml_deserialize.cpp`**
- XML 파일을 읽어 데이터를 파싱하고 `movie_list` 구조로 복원하는 기능을 담당합니다.
- **주요 함수**:
  - `deserialize(string_view filepath)`:
    - XML 파일을 읽고 데이터를 복원합니다.

### 4. **`xpath_selector.cpp`**
- XPath를 사용하여 XML 데이터를 검색하고 선택하는 기능을 제공합니다.
- **주요 함수**:
  - `select_with_xpath(const std::string &file)`:
    - XML 파일을 로드하여 XPath 쿼리를 실행하고 결과를 출력합니다.
    - **사용 예제**:
      - `/movies/movie[@year>1995]`: 연도가 1995보다 큰 `<movie>` 노드 선택.
      - `movies/movie/cast/role[last()]`: 각 `<movie>` 노드의 `<cast>`에서 마지막 `<role>` 노드 선택.

### 5. **`movie_data.h`**
- 영화 데이터의 구조를 정의하는 헤더 파일.
- **구조체**:
  - `casting_role`: 배우와 역할 정보를 포함.
  - `movie`: 영화의 ID, 제목, 개봉 연도, 길이, 출연진, 감독, 작가 정보를 포함.
  - `movie_list`: 영화의 목록을 `std::vector`로 저장.

---

## 사용 방법
### 1. **직렬화**
1. `main.cpp`에서 `movie_list` 데이터를 초기화합니다.
2. `serialize()` 함수를 호출해 데이터를 XML 파일로 저장합니다.
3. 결과 파일(`movies.xml`)이 프로젝트 디렉토리에 생성됩니다.

### 2. **디시리얼라이즈**
1. XML 파일(`movies.xml`)을 읽어 `deserialize()` 함수로 데이터를 복원합니다.
2. 복원된 데이터를 확인하거나 수정 가능합니다.

### 3. **XPath 데이터 선택**
`xpath_selector.cpp` 파일에서 제공하는 `select_with_xpath()` 함수를 호출하여 XML 데이터를 선택하고 처리할 수 있습니다.

---

## 개발 환경
- **IDE**: Visual Studio Code (VS Code)
- **사용한 C++ 버전**: C++17
- **컴파일러**: g++ 8.1.0 (x86_64-posix-sjlj-rev0, MinGW-W64)

---

## 의존성
- **PugiXML**: XML 처리를 위한 경량 라이브러리.
  - [PugiXML GitHub 페이지](https://github.com/zeux/pugixml)

---

## 빌드 및 실행
### 1. **컴파일**
터미널에서 다음 명령어를 실행하세요:
```bash
g++ -std=c++17 -g src/main.cpp src/xml_serialize.cpp src/xml_deserialize.cpp src/xpath_selector.cpp third_party/pugixml/pugixml.cpp -o main.exe