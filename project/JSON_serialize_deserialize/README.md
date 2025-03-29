# JSON 직렬화 및 디시리얼라이즈

## 프로젝트 개요
이 프로젝트는 영화 데이터를 JSON 형식으로 직렬화(Serialize)하거나, JSON 파일에서 데이터를 읽어와 디시리얼라이즈(Deserialize)하는 기능을 구현합니다. 영화 데이터는 영화 ID, 제목, 개봉 연도, 길이, 출연진, 감독, 작가 정보를 포함합니다.

---

## 주요 파일

### **`movie_data.h`**
- 영화 데이터를 정의하는 헤더 파일입니다.
- 주요 데이터 구조:
  - `casting_role`: 배우와 역할 정보를 저장.
  - `movie`: 영화의 ID, 제목, 개봉 연도, 길이, 출연진, 감독, 작가 정보를 포함.
  - `movie_list`: 영화 목록을 저장하는 `std::vector` 구조.

### **`json_serialize.cpp`**
- 영화 데이터를 JSON으로 변환하고 파일에 저장하는 기능을 제공합니다.
- 주요 함수:
  - `to_json`: `casting_role` 및 `movie` 데이터를 JSON 객체로 변환.
  - `serialize`: `movie_list` 데이터를 JSON 파일로 직렬화.

### **`json_deserialize.cpp`**
- JSON 파일에서 데이터를 읽어와 `movie_list` 구조로 복원하는 기능을 제공합니다.
- 주요 함수:
  - `parse_movie`: JSON 객체를 `movie` 객체로 변환.
  - `deserialize`: JSON 파일을 읽고 데이터를 `movie_list`로 디시리얼라이즈.

### **`main.cpp`**
- 전체 기능을 테스트하는 실행 파일입니다.
- 주요 작업:
  1. 영화 데이터를 초기화.
  2. `serialize`를 통해 JSON 파일로 저장.
  3. `deserialize`를 통해 JSON 파일에서 데이터를 읽어 확인.
  4. 데이터의 일관성을 검증하며, 결과를 출력.

---

## 사용 방법

### **컴파일**
1. 아래 명령어로 프로젝트를 컴파일하세요.
   ```bash
   g++ -std=c++17 -o main main.cpp