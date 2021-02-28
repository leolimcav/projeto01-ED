#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <climits>
#include "../include/List.h"
using namespace std;

int main()
{
  vector<List *> lists; // array that store all the created lists

  cout << "To see the list of commands type 'help'" << endl;
  while (true)
  {
    string cmd;
    getline(cin, cmd);

    std::stringstream ss{cmd};
    vector<string> tokens;
    string buffer;

    while (ss >> buffer)
    {
      tokens.push_back(buffer);
    }

    if (tokens[0] == "exit" && tokens.size() == 1)
    {
      int lists_size = lists.size();
      for (int i = 0; i < lists_size; ++i)
      {
        delete lists[i];
        lists[i] = nullptr;
      }
      lists.clear();
      break;
    }
    // createlist
    else if (tokens[0] == "createlist" && tokens.size() == 1)
    {
      List *l = new (std::nothrow) List();
      lists.push_back(l);
      if (l != nullptr)
        cout << "List " << lists.size() - 1 << " created successfully!" << endl;
    }
    // pushback [x] list [k]
    else if (tokens[0] == "pushback" && tokens.size() == 4)
    {
      int x = std::stoi(tokens[1]);
      int k = std::stoi(tokens[3]);
      lists[k]->push_back(x);
      cout << x << " added to the end of the list " << k << endl;
    }
    // pushfront [x] list [k]
    else if (tokens[0] == "pushfront" && tokens.size() == 4)
    {
      int x = std::stoi(tokens[1]);
      int k = std::stoi(tokens[3]);
      lists[k]->push_front(x);
      cout << x << " added to the beginning of the list " << k << endl;
    }
    // insertafter [pos] [key] list [k]
    else if (tokens[0] == "insertafter" && tokens.size() == 5)
    {
      int pos = std::stoi(tokens[1]);
      int key = std::stoi(tokens[2]);
      int k = std::stoi(tokens[4]);
      lists[k]->insertAfter(key, pos);
      cout << key << " added after the position " << pos << " of the list " << k << endl;
    }
    // remove [x] list [k]
    else if (tokens[0] == "remove" && tokens.size() == 4)
    {
      int x = std::stoi(tokens[1]);
      int k = std::stoi(tokens[3]);
      lists[k]->remove(x);
    }
    // removeall [x] list [k]
    else if (tokens[0] == "removeall" && tokens.size() == 4)
    {
      int x = std::stoi(tokens[1]);
      int k = std::stoi(tokens[3]);
      lists[k]->removeAll(x);
    }
    // popfront [k]
    else if (tokens[0] == "popfront" && tokens.size() == 2)
    {
      int k = std::stoi(tokens[1]);
      int elem = lists[k]->pop_front();
      if (elem != INT_MIN)
        cout << elem << " removed from the beginning of the list " << k << endl;
      else
        cout << " unable to remove from the beginning of the list " << k << endl;
    }
    // popback [k]
    else if (tokens[0] == "popback" && tokens.size() == 2)
    {
      int k = std::stoi(tokens[1]);
      int elem = lists[k]->pop_back();
      if (elem != INT_MIN)
        cout << elem << " removed from the end of the list " << k << endl;
      else
        cout << " unable to remove from the end of the list " << k << endl;
    }
    // empty [k]
    else if (tokens[0] == "empty" && tokens.size() == 2)
    {
      int k = std::stoi(tokens[1]);
      if (lists[k]->empty())
        cout << "list " << k << " is empty!" << endl;
      else
        cout << "list " << k << " have elements!" << endl;
    }
    // size [k]
    else if (tokens[0] == "size" && tokens.size() == 2)
    {
      int k = std::stoi(tokens[1]);
      cout << "The size of the list " << k << " = " << lists[k]->size() << endl;
    }
    // clear [k]
    else if (tokens[0] == "clear" && tokens.size() == 2)
    {
      int k = std::stoi(tokens[1]);
      lists[k]->clear();
      cout << "list " << k << " cleared!" << endl;
    }
    // print [k]
    else if (tokens[0] == "print" && tokens.size() == 2)
    {
      int k = std::stoi(tokens[1]);
      cout << "list " << k << " = ";
      lists[k]->print();
    }
    // printreverse [k]
    else if (tokens[0] == "printreverse" && tokens.size() == 2)
    {
      int k = std::stoi(tokens[1]);
      cout << "list " << k << " = ";
      lists[k]->printReverse();
    }
    // contains [x] list [k]
    else if (tokens[0] == "contains" && tokens.size() == 4)
    {
      int x = std::stoi(tokens[1]);
      int k = std::stoi(tokens[3]);
      if (lists[k]->contains(x))
        cout << x << " is in the list " << k << endl;
      else
        cout << x << " NOT in the list " << k << endl;
    }
    // concat list [x] list [k]
    else if (tokens[0] == "concat" && tokens.size() == 5)
    {
      int x = std::stoi(tokens[2]);
      int k = std::stoi(tokens[4]);
      lists[x]->concat(lists[k]);
      cout << "List " << k << " concatenated with list " << x << endl;
    }
    // copyarray size [x] array [n] list [k]
    else if (tokens[0] == "copyarray" && tokens.size() >= 7)
    {
      int n = std::stoi(tokens[2]);
      int array[n] = {};
      for (int i = 0; i < n; i++)
      {
        array[i] = std::stoi(tokens[4 + i]);
      }
      int k = std::stoi(tokens[4 + (n + 1)]);
      lists[k]->copyArray(n, array);
      cout << "Array with " << n << " elements copied to the list " << k << endl;
    }
    // copy list [k]
    else if (tokens[0] == "copy" && tokens.size() == 3)
    {
      int k = std::stoi(tokens[2]);
      List *copiedList = lists[k]->copy();
      lists.push_back(copiedList);
      int lists_size = lists.size();
      cout << "List " << k << " copied to List " << lists_size - 1 << endl;
    }
    // equal list [x] list [k]
    else if (tokens[0] == "equal" && tokens.size() == 4)
    {
      int x = std::stoi(tokens[2]);
      int k = std::stoi(tokens[4]);
      if (lists[x]->equal(lists[k]))
        cout << "The lists " << x << " and " << k << " are equal!" << endl;
      else
        cout << "The lists " << x << " and " << k << " are different!" << endl;
    }
    // help
    else if (tokens[0] == "help" && tokens.size() == 1)
    {
      cout << "*** List of Commands ***"
           << "\n"
           << "createlist -- initialize an empty list"
           << "\n"
           << "pushback x list y -- insert the value x to the end of the list y"
           << "\n"
           << "pushfront x list y -- insert the value x to the beginning of the list y"
           << "\n"
           << "insertafter y x list z -- insert the value x after the position y of the list z"
           << "\n"
           << "remove x list y -- remove the value x of the list y"
           << "\n"
           << "removeall x list y -- remove all the values equal to x of the list y"
           << "\n"
           << "popfront list x -- remove from the beginning of the list x"
           << "\n"
           << "popback list x -- remove from the end of the list x"
           << "\n"
           << "empty x -- check if the list x is empty"
           << "\n"
           << "size x -- print the size of the list x"
           << "\n"
           << "clear x -- remove all the nodes from the list x"
           << "\n"
           << "print x -- print the nodes of the list x"
           << "\n"
           << "printreverse x -- print the nodes of the list x in reverse order"
           << "\n"
           << "contains x list y -- check if the value x exists in list y"
           << "\n"
           << "concat list x list y -- concatenate the values of list y to the end of list x"
           << "\n"
           << "copyarray size n array [x, ... n] list y -- add the values of the array of size n to the list y. Ex: copyarray size 3 array 1 2 3 list 0"
           << "\n"
           << "copy list x -- create a new list y that is a copy the list x"
           << "\n"
           << "equal list x list y -- check if the list y is equal to the list x"
           << endl;
    }
    else
    {
      cout << "command not found! type 'help' to see the list of commands!" << endl;
    }
  }
  return 0;
}
