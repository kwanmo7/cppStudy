#ifndef MOVIE_DATA_H
#define MOVIE_DATA_H
#include <string>
#include <vector>
#include <string_view>

using namespace std;

struct casting_role
{
  string actor;
  string role;
};

struct movie
{
  unsigned int id;
  string title;
  int year;
  unsigned int length;
  vector<casting_role> cast;
  vector<string> directors;
  vector<string> writers;
};

using movie_list = vector<movie>;

#endif // MOVIE_DATA_H