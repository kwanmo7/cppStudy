#include "../include/movie_data.h"
#include "../third_party/pugixml/pugixml.hpp"
#include <iostream>

using namespace std;

// movie_list를 XML 파일로 serialize
void serialize(movie_list const & movies, string_view filepath){
  // XML 문서 객체 생성
  pugi::xml_document doc;

  // 루트 노드 movies 추가
  auto root = doc.append_child("movies");

  // 각 영화에 대해 노드 생성
  for(auto const & m : movies){
    auto movie_node = root.append_child("movie"); // movie 노드 추가

    movie_node.append_attribute("id").set_value(m.id); // 영화 id
    movie_node.append_attribute("title").set_value(m.title); // 영화 제목
    movie_node.append_attribute("year").set_value(m.year); // 개봉 연도
    movie_node.append_attribute("length").set_value(m.length); // 영화 길이

    // 출연진 정보 노드 추가
    auto cast_node = movie_node.append_child("cast");
    for(auto const & c : m.cast){
      auto node = cast_node.append_child("role"); // role 노드 추가
      node.append_attribute("star").set_value(c.actor.c_str()); // 배우 이름
      node.append_attribute("name").set_value(c.role.c_str()); // 배역 이름
    }

    // 감독 정보 노드 추가
    auto directors_node = movie_node.append_child("directors");
    for(auto const & director : m.directors){
      directors_node.append_child("director") // director 노드 추가
                    .append_attribute("name")
                    .set_value(director.c_str()); // 감독 이름
    }

    // 작가 정보 노드 추가
    auto writers_node = movie_node.append_child("writers");
    for(auto const & writer : m.writers){
      writers_node.append_child("writer") // writer 노드 추가
                  .append_attribute("name")
                  .set_value(writer.c_str()); // 작가 이름
    }
  }

  // XML 파일 저장
  if(!doc.save_file(filepath.data())){
    cerr << "Error : Failed to save XML file to " << filepath << endl;
  }
}