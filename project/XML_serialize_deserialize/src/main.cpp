#include "../include/movie_data.h"
#include "xml_serialize.cpp"
#include "xml_deserialize.cpp"
#include "xpath_selector.cpp"
#include <cassert>

int main(){
  movie_list movies{
    {
      11000, "Matrix", 1999, 196,
      { {"Reeves", "Neo"},
        {"Laurence Fishburne", "Morpheus"},
        {"Moss", "Trinity"},
        {"Weaving", "Smith"} },
      {"Wachowski", "Wachowski"},
      {"Lana", "Lilly"},
    },
    {
      9898, "riot", 2009, 333,
      { {"Tom", "KKA"},
        {"Fish", "Tiger"},
        {"Lion", "heart"},
        {"Bird", "snake"} },
      {"あいうえお"},
      {"가나다라마", "7e5f5e"},
    }
  };

  serialize(movies, "movies.xml");

  auto result = deserialize("movies.xml");

  assert(result.size() == 2);
  assert(result[0].title == "Matrix");
  assert(result[1].title == "riot");

  select_with_xpath("movies.xml");

}