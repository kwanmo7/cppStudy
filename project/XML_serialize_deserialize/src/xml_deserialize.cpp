#include "../include/movie_data.h"
#include "../third_party/pugixml/pugixml.hpp"
#include <iostream>

using namespace std;

// 영화 데이터 검증 함수
bool validate_movie(const movie &m){
  if(m.id == 0){
    cerr << "Error: Movie ID is missing or invalid." << endl;
    return false;
  }
  if(m.title.empty()){
    cerr << "Error: Movie title is empty." << endl;
    return false;
  }
  if(m.year == 0){
    cerr << "Error: Movie year is missing or invalid." << endl;
    return false;
  }

  return true;
}

// XML 파일을 읽어와 movie_list로 deserialize
movie_list deserialize(string_view filepath){
  // XML 문서를 저장할 객체 생성
  pugi::xml_document doc;
  // 반환할 영화 데이터 리스트
  movie_list movies;
  
  // XML 파일 로드
  auto result = doc.load_file(filepath.data());
  // 파일 로드 성공 시
  if(result){
    auto root = doc.child("movies");
    for(auto movie_node = root.child("movie");
        movie_node;
        movie_node = movie_node.next_sibling("movie")){

          // 영화 데이터 저장용 객체 생성
          movie m;

          m.id = movie_node.attribute("id").as_uint(); // id
          m.title = movie_node.attribute("title").as_string(); // 제목
          m.year = movie_node.attribute("year").as_uint(); // 개봉 연도
          m.length = movie_node.attribute("length").as_uint(); // 영화 길이

          // 출연진 정보 파싱
          for(auto role_node : movie_node.child("cast").children("role")){
            m.cast.push_back(casting_role{
              role_node.attribute("star").as_string(),
              role_node.attribute("name").as_string()});
          }

          // 감독 정보 파싱
          for(auto director_node : movie_node.child("directors").children("director")){
            m.directors.push_back(director_node.attribute("name").as_string());
          }
          
          // 작가 정보 파싱
          for(auto writer_node : movie_node.child("writers").children("writer")){
            m.writers.push_back(writer_node.attribute("name").as_string());
          }
          
          // 파싱된 영화 데이터 검증 후 리스트에 추가
          if(validate_movie(m)){
            movies.push_back(m);
          }else{
            cerr << "Skipping invalid movie entry." << endl;
          }
    }
  }else{
    cerr << "Error: Failed to load XML file : " << filepath << endl;
  }

  return movies;
}