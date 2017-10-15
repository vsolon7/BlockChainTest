#include "BlockChain.h"



BlockChain::BlockChain()
{
	//when you create the chain, add the root block!
	addBlock("");
}

void BlockChain::addBlock(std::string data, int nonce)
{
	std::vector<BYTE> prevHash(32);
	Block *prevBlock;

	//if there are no blocks in the blocklist, this is the root block
	//and as a result, it has no previous block to point to.
	if (_blockList.size() == 0)
		prevBlock = nullptr;
	else
		prevBlock = _blockList.back();

	//add this block to the chain!
	_blockList.push_back(new Block(data, prevHash, prevBlock, nonce, _blockList.size()));
	_blockList.back()->setHash();
}

void BlockChain::editBlockData(int pos, std::string data)
{
	_blockList[pos]->blockData = data;
	_updateHash(pos);
}

void BlockChain::_updateHash(int pos)
{
	for (int i = pos; i < _blockList.size(); i++)
	{
		_blockList[i]->setHash();
	}
}

//TODO
void BlockChain::mine()
{
	
}

BlockChain::~BlockChain()
{
	//make sure to delete memory allocated on the heap!
	for (int i = 0; i != _blockList.size(); i++)
	{
		delete _blockList[i];
	}
}
