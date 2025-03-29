#include "../include/movie_data.h"
#include "../third_party/nlohmann/json.hpp"
#include <fstream>
#include <iostream>

using json = nlohmann::json;
using namespace std;

// json 데이터 매핑
movie parse_movie(const json &e){
  // 임시 movie 객체 생성
  movie m;

  // movie 필드 설정
  m.id = e.at("id").get<unsigned int>();
  m.title = e.at("title").get<string>();
  m.year = e.at("year").get<unsigned int>();
  m.length = e.at("length").get<unsigned int>();

  // cast 배열 처리
  for(auto & role : e.at("cast")){
    m.cast.push_back(casting_role{
    role.at("star").get<string>(),
    role.at("name").get<string>()});
  }

  // directors 배열 처리
  for(auto & director : e.at("directors")){
    m.directors.push_back(director);
  }

  // writers 배열 처리
  for(auto & writer : e.at("writers")){
    m.writers.push_back(writer);
  }

  return m;
}

// JSON 파일을 읽어와 movie_list로 디시리얼라이즈하는 함수
movie_list deserialize(string_view filepath){
  // 결과를 저장할 movie_list 객체
  movie_list movies;

  // 파일 입력 스트림 생성
  ifstream ifile(filepath.data());
  // 파일이 열렸는지 확인
  if(ifile.is_open()){
    json jdata;

    try{
       // 파일 데이터를 JSON 객체로 읽기
      ifile >> jdata;

      // JSON 객체 확인 및 처리
      if(jdata.is_object()){
        // "movies" 배열을 순회하며 movie 구조체를 생성
        for(auto & e : jdata.at("movies")){
          // 완성된 movie 객체를 movie_list에 추가
          // 복사를 하지 않고 move() 함수를 이용하여 성능 최적화
          movies.push_back(move(parse_movie(e)));
        }
      }
    }catch(exception const & ex){
      cout << ex.what() << endl;
    }
  }else{
    cerr << "Error: Unable to open file '" << filepath << "'. Check the file path and permissions." << endl;
  }

  return movies;
}