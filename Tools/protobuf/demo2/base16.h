
#ifndef BASE16_H
#define BASE16_H

#include <string>
#include <vector>

bool encode_base16(std::string& out, const std::string& in);
bool encode_base16(std::string& out, const std::vector<unsigned char>& in);
bool encode_base16(std::vector<unsigned char>& out, const std::string& in);
bool encode_base16(std::vector<unsigned char>& out, const std::vector<unsigned char>& in);
bool encode_base16(std::string& str_out, const unsigned char *in, int in_len);

bool decode_base16(std::string& out, const std::string& in);
bool decode_base16(std::string& out, const std::vector<unsigned char>& in);
bool decode_base16(std::vector<unsigned char>& out, const std::string& in);
bool decode_base16(std::vector<unsigned char> &out, const std::vector<unsigned char>& in);
bool decode_base16(unsigned char* out, const std::string& str_in);

#endif // BASE16_H
