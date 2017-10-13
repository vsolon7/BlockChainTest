#pragma once

#include <string>
#include <vector>

#include "Block.h"

typedef std::vector<Block *> Chain;

class BlockChain
{
public:
	BlockChain();
	~BlockChain();

/* 
	add a block to the block, takes the data you want to add to the block
	and an optional nonce you can assign to it
*/
	void addBlock(std::string data, int nonce = 0);

/* 
	if you want to edit the data of a block, you use this.
	after editing, will update all the blocks hashes in the chain 
*/
	void editBlockData(int pos, std::string data);

/*
	mine a block to find a nonce to fit the right hash
*/
	void mine();
private:

/* 
	updates the block hashes so that if you change a block that isn't the last one
	then the other block hashes will be updated all down the line, till the end
	only used by the blockchain after edit block, don't want anyone to just update
	hashes willy nilly. 
*/
	void _updateHash(int);

/*
	a vector of pointers to all the blocks (in order)
	this way we can see which block came before another,
	and it helps with setting hashes of previous blocks
*/
	Chain _blockList; 
};

