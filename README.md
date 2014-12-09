#Review of a Doxygen validator

See the analyzed project: https://github.com/Bender250/pa193/

## Tokenizer
* Tokens might overlap in any way. It makes more tricky to write the parser properly, so it is a poor design decision in my view.
* Tokenizer removes all backslashes in removeBackslashes method.
	* First, it is problematic for correctness reasons, but if we use it only as a validator, this seems to be OK.
	* Second, it changes the input string and consequently changes the string passed to `Tokenizer::tokenize(std::string&)`, which might be weird for the library user and is not documented.
	* Moreover, this feature seems to be required for correct functionality. If we removed the '&', the parser would get wrong positions of the tokens. However, it seems that it could lead "only" to wrong parsing (and consequently to false positive/negative). However, it can never result in `std::out_of_range` thrown by `std::string::substr(std::string::size_type, std::string::size_type)` or in some overrun.
	* When user passes two different instances of the same string to tokenizer and parser, in can also lead in unexpected results.
	* When user wants to read the string after passing it to the tokenizer, he might get some unexpected results.
	* When there is a large "\n\n\n\n..." sequence, it takes `O(n^2)` time, which can be used for DoS in some cases (e.g. online validator).
* Except the `removeBackslashes` funtion, it is good that the tokenizer always finishes in a linear time with respect to the input length. (Not doing so might make it vulnerable to DoS attacks.)

When considering the tokenizer alone, it has a tricky API with some tricky undocumented (but seemingly intended) behaviour. When considering the tokenizer and how it is used in the `main.cpp` file, it works correctly. However, the design (namely overlapping tokens) makes it hard for the parser to process the tokenizer output correctly.

## Parser
* As noted in tokenizer, it assumes that it has input with `\` escape sequences filtered out by the tokenizer.
* The parser seems to be very stateful.
* TODO: To be analyzed deeper
* Some wrongly processed inputs found. (No memory corruption so far, though.) See the `successful` directory.
* It uses modern safe C++, which is not so much error prone as old C functions.
