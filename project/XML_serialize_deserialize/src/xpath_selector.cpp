#include "../third_party/pugixml/pugixml.hpp"
#include <iostream>
#include <string>

using namespace std;

// XPath를 사용하여 XML 데이터를 선택하는 함수
void select_with_xpath(const string &file){
  // XML 문서를 저장할 객체
  pugi::xml_document doc;
  // XML 파일 로드
  if(doc.load_file(file.c_str())){
    cout << "File loaded successfully: " << file << endl;
    try{
      // XPath 쿼리 : 연도가 1995보다 큰 movie 노드 선택
      auto titles = doc.select_nodes("/movies/movie[@year>1995]");

      // 선택된 movie 노드 출력
      for(auto it : titles){
        cout << it.node().attribute("title").as_string() << endl;
      }
    }catch(pugi::xpath_exception const &e){
      cout << e.result().description() << endl;
    }

    try{
      // XPath 쿼리 : 각 movie 노드의 cast의 마지막 role을 선택
      auto titles = doc.select_nodes("movies/movie/cast/role[last()]");

      // 선택된 role 노드 출력
      for(auto it : titles){
        cout << it.node().attribute("star").as_string() << endl;
      }
    }catch(pugi::xpath_exception const &e){
      cout << e.result().description() << endl;
    }
  }else{
    cerr << "Error: Unable to load file " << file << endl;
  }
}