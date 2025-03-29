#include "json_serialize.cpp"
#include "json_deserialize.cpp"
#include <assert.h>

// movie_list의 내용을 출력하는 함수
void print_movie_list(const movie_list& movies) {
  for (const auto& movie : movies) {
      std::cout << "Movie ID: " << movie.id << "\n";
      std::cout << "Title: " << movie.title << "\n";
      std::cout << "Year: " << movie.year << "\n";
      std::cout << "Length: " << movie.length << " minutes\n";

      std::cout << "Cast:\n";
      for (const auto& cast : movie.cast) {
          std::cout << "  - " << cast.actor << " as " << cast.role << "\n";
      }

      std::cout << "Directors:\n";
      for (const auto& director : movie.directors) {
          std::cout << "  - " << director << "\n";
      }

      std::cout << "Writers:\n";
      for (const auto& writer : movie.writers) {
          std::cout << "  - " << writer << "\n";
      }

      std::cout << "-------------------------------------\n";
  }
}

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

  serialize(movies, "movies.json");

  auto movies2 = deserialize("movies.json");

  assert(movies2.size() == 2);
  assert(movies2[0].title == "Matrix");
  assert(movies2[1].title == "riot");

  print_movie_list(movies2);
}