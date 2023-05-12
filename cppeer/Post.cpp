/*
 *
 * This code is copyrighted (c) 2021 by
 * Texas A&M Computer Science
 *
 *	There will be RIGOROUS cheat checking on your exams!!
 *	DON'T POST ANYWHERE!! such as CHEGG, public Github, etc
 *  You will be legally responsible.
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>
#include <cctype>
#include "Post.h"

using std::string;
using std::vector;

Post::Post(unsigned int postId, string userName, string postText)
  : postId(postId), userName(userName), postText(postText) {
  if (postId == 0 || userName == "" || postText == "") {
    throw std::invalid_argument("post constructor: invalid parameter values");
  }
}

unsigned int Post::getPostId() {
  return postId;
}

string Post::getPostUser() {
  return userName;
}

string Post::getPostText() {
  return postText;
}

vector<string> Post::findTags() {
  // TODO(student): extracts candidate tags based on occurrences of # in the post
  vector<string> Tag;
  std::stringstream ss(postText);
  string sst;
  ss >> sst;
  while(!ss.fail())
  {
    string str = "";
    if(sst[0] == '#')
    {
      for(int i = 0; i < sst.size(); i++)
      {
        //break at punctuation
        if(sst[i] == '!' || sst[i] == ',' || sst[i] == '.' || sst[i] == '?'){break;}
        str += tolower(sst[i]);
      }
      Tag.push_back(str);
    }
    ss >> sst;
  }
  this->postText = postText;
  return Tag;
}
