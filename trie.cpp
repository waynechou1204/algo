// this is a algorithm of trie tree to get pre-fix of the words
//input: N
// N rows of dictionnary words
// m
// M rows of query pre-fixs

#include <map>
#include <iostream>
#include <string>

using namespace std; 

class trieNode
{
public:
	int count;
	map<char, trieNode*> sons;

	trieNode(){
		count = 0;
	}
	~trieNode();

	bool hasCharacter(char c){
		if (sons.count(c))
		{
			return true;
		}
		return false;
	}

	trieNode* addCharacter(char c){
		trieNode* tmp = new trieNode();
		sons[c]=tmp;
		return sons[c];
	}

	trieNode* getSon(char c){
		if (hasCharacter(c))
		 {
		 	return sons[c];
		 } 
		 return NULL;
	}
};

int main()
{
	trieNode* root = new trieNode();
	trieNode* current = root;

	int dictNum=0;
	cin >> dictNum;

	string word;
	
	// construct tree
	for (int n = 0; n < dictNum; ++n)
	{
		cin >> word;
		for (int i = 0; i < word.length(); ++i)
		{
			if (current->hasCharacter(word[i])){
				current = current->getSon(word[i]);
			}
			else{
				current = current->addCharacter(word[i]);
			}
			current->count++;
		}
		current = root;
	}

	int reqNum=0;
	cin >> reqNum;

	string req;
	
	// query word tree
	for (int n = 0; n < reqNum; ++n)
	{
		current = root;
		cin >> word;
		int i=0;
		for (; i < word.length(); ++i)
		{
			if (current->hasCharacter(word[i])){
				current = current->getSon(word[i]);
			}
			else{
				break;
			}
		}
		if(i==word.length())
		{
			cout << current->count << endl;
		}
		else{
			cout << 0 << endl;
		}
	}


	return 0;
}