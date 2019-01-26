std::string iso_8859_1_to_utf8(std::string &str)
{
    string strOut;
    for (std::string::iterator it = str.begin(); it != str.end(); ++it)
    {
        uint8_t ch = *it;
        if (ch < 0x80) {
            strOut.push_back(ch);
        }
        else {
            strOut.push_back(0xc0 | ch >> 6);
            strOut.push_back(0x80 | (ch & 0x3f));
        }
    }
    return strOut;
}

char* iso88959_to_utf8(const char *str)
{
    char *utf8 = malloc(1 + (2 * strlen(str)));

    if (utf8) {
        char *c = utf8;
        for (; *str; ++str) {
            if (*str & 0x80) {
                *c++ = *str;
            } else {
                *c++ = (char) (0xc0 | (unsigned) *str >> 6);
                *c++ = (char) (0x80 | (*str & 0x3f));
            }
        }
        *c++ = '\0';
    }
    return utf8;
}

size_t iso8859_1_to_utf8(char *content, size_t max_size)
{
    char *src, *dst;

    //first run to see if there's enough space for the new bytes
    for (src = dst = content; *src; src++, dst++)
    {
        if (*src & 0x80)
        {
            // If the high bit is set in the ISO-8859-1 representation, then
            // the UTF-8 representation requires two bytes (one more than usual).
            ++dst;
        }
    }

    if (dst - content + 1 > max_size)
    {
        // Inform caller of the space required
        return dst - content + 1;
    }

    *(dst + 1) = '\0';
    while (dst > src)
    {
        if (*src & 0x80)
        {
            *dst-- = 0x80 | (*src & 0x3f);                     // trailing byte
            *dst-- = 0xc0 | (*((unsigned char *)src--) >> 6);  // leading byte
        }
        else
        {
            *dst-- = *src--;
        }
    }
    return 0;  // SUCCESS
}