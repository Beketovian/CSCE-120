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
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Network.h"

using std::string;
using std::vector;

Network::Network() {
  // empty containers of vectors already created
  // no implementation is needed here
}

void Network::loadFromFile(string fileName) {
  // TODO(student): load user and post information from file
  std::ifstream IFS(fileName);
  if(IFS.fail()){throw std::invalid_argument("file fail to open");}
  string str;
  IFS >> str;
  while(IFS.eof() == false)
  {
    if(str == "User")
    {
      string file;
      IFS >> file;
      if(IFS.fail()){throw std::runtime_error("IFS fail 1");}
      IFS >> str;
      if(IFS.fail()){throw std::runtime_error("IFS fail 1");}
      try
      {
        addUser(file);
      }
      catch(...)
      {
       throw std::runtime_error("User fail 1"); 
      }      
    }
    else if(str == "Post")
    {
      int ID;
      string file;
      string text;
      string utext = "";
      IFS >> ID;
      IFS >> file;
      IFS >> text;
      if(text == "Post" || text == "User"){throw std::runtime_error("invalid");}
      utext += text;
      bool done = false;
      while(!done)
      {
        IFS >> text;
        if(IFS.fail() || IFS.eof()){break;}
        if(text == "User" || text == "Post")
        {
          str = text;
          done = true;
          break;
        }
        utext += " ";
        utext += text;
      }
      try
      {
        addPost(ID, file, utext);
        utext = "";
      }
      catch(...)
      {
        throw std::runtime_error("invalid 2");
      }
    }
    else{throw std::runtime_error("invalid 3");}
  }
}

void Network::addUser(string userName) {
  // TODO(student): create user and add it to network
  if(userName == ""){throw std::invalid_argument("username invalid");}
  for(int i = 0; i < userName.size(); i++)
  {
    if(isalpha(userName[i])){userName[i] = tolower(userName[i]);}
  }
  for(int i = 0; i < users.size(); i++)
  {
    if(users[i]->getUserName() == userName){throw std::invalid_argument("duplicate usernames");}
  }
  users.push_back(new User(userName));
  std::cout << "Added User " << userName << std::endl;
}

void Network::addPost(unsigned int postId, string userName, string postText) {
  // TODO(student): create post and add it to network
  bool cp = false;
  int ui;
  if(postText == ""){throw std::invalid_argument("posttext invalid");}
  for(int i = 0; i < posts.size(); i++)
  {
    if(postId == posts[i]->getPostId()){throw std::invalid_argument("duplicate postid");}
  }
  for(int i = 0; i < users.size(); i++)
  {
    if(userName == users[i]->getUserName())
    {
      cp = true;
      ui = i;
    }
  }
  if(!cp){throw std::invalid_argument("no username");}
  Post* temp = new Post(postId, userName, postText);
  posts.push_back(temp);
  users[ui]->addUserPost(temp);

  vector<string> pt;
  pt = temp->findTags();
  bool valid = false;
  for(int i = 0; i < pt.size(); i++)
  {
    valid = false;
    for(int j = 0; j < tags.size(); j++)
    {
      if(pt[i] == tags[j]->getTagName())
      {
        tags[j]->addTagPost(temp);
        valid = true;
      }
    }
    if(!valid)
    {
      Tag *TU;
      try
      {
        TU = new Tag(pt[i]);
      }
      catch(...)
      {
        continue;
      }
      TU->addTagPost(temp);
      tags.push_back(TU);
    }
  }
  std::cout << "Added Post " << postId << " by " << userName << std::endl;
}

vector<Post*> Network::getPostsByUser(string userName) {
  // TODO(student): return posts created by the given user
  if(userName == ""){throw std::invalid_argument("username invalid");}
  vector<Post*> userposts;
  bool founduser = false;
  int n;
  for(int i = 0; i < users.size();i++)
  {
    if(userName == users[i]->getUserName())
    {
      founduser = true;
      userposts = users[i]->getUserPosts();
    }
  }
  if(!founduser){throw std::invalid_argument("username not found");}
  return userposts;
}

vector<Post*> Network::getPostsWithTag(string tagName) {
  // TODO(student): return posts containing the given tag
  if(tagName == ""){throw std::invalid_argument("tagname invalid");}
  bool foundtag = false;
  for(int i = 0; i < tags.size(); i++)
  {
    if(tags[i]->getTagName() == tagName)
    {
      foundtag = true;
      break;
    }
  }
  //if(!foundtag){throw std::invalid_argument("no tag");}
  std::vector<Post*> tagpost;
  for(int i = 0; i < tags.size(); i++)
  {
    if(tags[i]->getTagName() == tagName){tagpost = tags[i]->getTagPosts();}
  }
  return tagpost;
}

vector<string> Network::getMostPopularHashtag() {
  // TODO(student): return the tag occurring in most posts
  vector<string> t;
  int size = 0;
  for(int i = 0; i < tags.size(); i++)
  {
    int sizeat = tags[i]->getTagPosts().size();
    if(sizeat > size){size = sizeat;}
  }
  for(int i = 0; i < tags.size(); i++)
  {
    int sizeat = tags[i]->getTagPosts().size();
    if(size == sizeat)
    {
      t.push_back(tags[i]->getTagName());
    }
  }
  return t;
}

/**
  * Destructor
  * Do not change; already implemented.
  */
Network::~Network() {
  for (unsigned int i = 0; i < users.size(); ++i) {
    delete users.at(i);
  }
  for (unsigned int i = 0; i < tags.size(); ++i) {
    delete tags.at(i);
  }
  for (unsigned int i = 0; i < posts.size(); ++i) {
    delete posts.at(i);
  }
}
