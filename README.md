# BlockChainTest
Just me attempting to create a blockchain based on a few hours of reading about them.

Block is a struct of a block. Has a pointer to the previous block, a hash, hash to the previous block, data, and a (currently unused) 
nonce.

BlockChain is the blockchain object containing a vector of the blockchain (in order) and is used to add and edit blocks

picosha2 is used to generate hashes. You can find the creator here: https://github.com/okdshin/PicoSHA2

main creates and does some examples!
