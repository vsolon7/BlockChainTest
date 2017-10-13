#include <Windows.h>
#include <string>
#include <iostream>
#include <vector>

#include "picosha2.h"
#include "BlockChain.h"

int main()
{
	//create a blockchain
	BlockChain chain;

	//add blocks to the blockchain!
	for (int i = 1; i < 100; i++)
	{
		chain.addBlock("This is the block in position: " + std::to_string(i));
	}

	//a test edit of a block, all blocks after this one are updated!
	chain.editBlockData(23, "yo yo yo");

	system("pause");
	return 0;
}