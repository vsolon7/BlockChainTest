#pragma once

#include <string>
#include <vector>

#include "picosha2.h"

typedef unsigned char BYTE;

struct Block
{
	std::vector<BYTE> previousHash;
	std::string previousHashAsString;
	std::vector<BYTE> blockHash;
	std::string blockHashAsString;

	Block *previousBlock;

	std::string blockData;
	int blockNonce;

	//position in the blockChain
	int blockPosition;

	//the constructor for a block.
	//when you make a block, give it this info!
	Block(std::string data, std::vector<BYTE> prevHash, Block *prevBlock, int nonce, int p)
	{
		for (int i = 0; i != 32; i++)
			blockHash.push_back(0);

		blockData = data;
		previousHash = prevHash;
		previousHashAsString = picosha2::bytes_to_hex_string(previousHash);
		previousBlock = prevBlock;
		blockNonce = nonce;
		blockPosition = p;
	}

	//set the hash of a block!
	//for non root blocks, this is equal to the previous hash + the data of the current block + the nonce of the current block
	//
	//also, when we edit a block this is used to update all the chained blocks hashes!
	void Block::setHash()
	{

		//if the block has a previous block, create a hash for it which includes the previous blocks hash
		//if the block is the root block, then create a hash just based on its data
		if (previousBlock != nullptr)
		{
			//the previousHash value of this block is equal to the previous blocks hash. lol.
			previousHash = previousBlock->blockHash;
			previousHashAsString = picosha2::bytes_to_hex_string(previousHash);

			//create a hash for this block!
			picosha2::hash256((std::to_string(blockNonce) + blockData + picosha2::bytes_to_hex_string(previousHash)), blockHash);
		}	
		else
			picosha2::hash256((std::to_string(blockNonce) + blockData), blockHash);

		blockHashAsString = picosha2::bytes_to_hex_string(blockHash);
	}
};
