#include "../include/movie_data.h"
#include "../third_party/nlohmann/json.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>

using json = nlohmann::json;
using namespace std;

// casting_role 구조체를 JSON으로 변환하는 함수
void to_json(json& j, casting_role const & c){
  // casting_role의 actor와 role 값을 JSON 객체로 변환
  j = json{ {"star", c.actor}, {"name", c.role} };
}

// movie 구조체를 JSON으로 변환하는 함수
void to_json(json& j, movie const & m){

  // movie의 필드 값을 JSON 객체로 변환
  j = json::object({
    {"id", m.id},
    {"title", m.title},
    {"year", m.year},
    {"length", m.length},
    {"cast", m.cast},
    {"directors", m.directors},
    {"writers", m.writers}
  });
}

// movie_list 데이터를 JSON 파일로 직렬화하는 함수
void serialize(movie_list const & movies, string_view filepath){
  // movie_list 데이터를 JSON 객체로 변환
  json jdata{{"movies", movies}};

  // 파일 출력 스트림 생성
  std::ofstream ofile(filepath.data());
  if(ofile.is_open()){
    // JSON 데이터를 파일에 쓰기 (들여쓰기 2칸 적용)
    ofile << setw(2) << jdata << endl;
    cout << "File '" << filepath << "' has benn saved successfully." << endl;
  }else{
    cerr << "Error: Unable to open file " << filepath << endl;
    return;
  }
}