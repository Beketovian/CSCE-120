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
#include "Tag.h"
#include <cctype>

using std::string;
using std::vector;

Tag::Tag(string tagName) /* TODO(student): initialize */ {
  // TODO(student): implement constructor checks
  //check for invalid size
  if(tagName.size() < 2){throw std::invalid_argument("invalid argument");}
  //check for correct format
  if(tagName[0] != '#' || !(isalpha(tagName[1]))){throw std::invalid_argument("invalid argument");}
  //check for uppercase
  for(int i = 1; i < tagName.size(); i++)
  {
    if(isupper(tagName[i])){throw std::invalid_argument("invalid argument");}
  }
  //conseq. punct
  for(int i = 0; i < tagName.size(); i++)
  {
    if(tagName[i] == '!' || tagName[i] == ',' || tagName[i] == '.' || tagName[i] == '?'){throw std::invalid_argument("punctuation");}
  }
  //set this->tagName = tagName
    this->tagName = tagName;  
}

string Tag::getTagName() {
  // TODO(student): implement getter
  return tagName;
}

vector<Post*>& Tag::getTagPosts() {
  // TODO(student): implement getter
  return tagPosts;
}

void Tag::addTagPost(Post* post) {
  // TODO(student): add post to tag posts
  if(post == nullptr){throw std::invalid_argument("post is nullptr");}
  tagPosts.push_back(post);
}
