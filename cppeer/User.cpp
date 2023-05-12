/*
 *
 * This code is copyrighted (c) 2021 by
 * Texas A&M Computer Science
 *
 *	There will be RIGOROUS cheat checking on your exams!!
 *	DON'T POST ANYWHERE!! such as CHEGG, public Github, etc
 *  You will be legally responsible.
 */

#include <string>
#include <stdexcept>
#include "User.h"
#include <cctype>

using std::string;
using std::vector;

User::User(string userName) /* TODO(student): initialize */ {
  // TODO(student): implement constructor checks
  if(userName.size() == 0){throw std::invalid_argument("size 0");}
  if(isalpha(userName[0]) == false){throw std::invalid_argument("first letter not letter");}
  for(int i = 0; i < userName.size(); i++)
  {
    if(isupper(userName[i])){throw std::invalid_argument("no caps");} 
  }
  this->userName = userName;  
}

string User::getUserName() {
  // TODO(student): implement getter
  return userName;
}

vector<Post*>& User::getUserPosts() {
  // TODO(student): implement getter
  return userPosts;
}

void User::addUserPost(Post* post) {
  // TODO(student): add post to user posts
  if(post == nullptr){throw std::invalid_argument("post is nullptr");}
  userPosts.push_back(post);
}
