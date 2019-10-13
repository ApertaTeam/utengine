#include "ObjTestC.h"

#include <TextureHandler.h>

namespace UTSandbox
{
    ObjTestC::ObjTestC()
        : testTextTexture(TextureHandler::LoadTextureFromFile("font.png"))
    {
    }

    void ObjTestC::Init()
    {
        std::map testFontMap = std::map<char, Glyph>();

        testFontMap.insert(std::pair<char, Glyph>(' ', Glyph(' ', { 440, 158, 6, 32 }, 6, 0)));
        testFontMap.insert(std::pair<char, Glyph>('!', Glyph('!', { 430, 158, 8, 26 }, 12, 2)));
        testFontMap.insert(std::pair<char, Glyph>('"', Glyph('"', { 470, 158, 10, 16 }, 12, 0)));
        testFontMap.insert(std::pair<char, Glyph>('#', Glyph('#', { 228, 2, 14, 26 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('$', Glyph('$', { 32, 36, 12, 30 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('%', Glyph('%', { 388, 2, 14, 26 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('&', Glyph('&', { 404, 2, 14, 26 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('\'', Glyph('\'', { 102, 192, 4, 16 }, 6, 0)));
        testFontMap.insert(std::pair<char, Glyph>('(', Glyph('(', { 410, 158, 8, 26 }, 10, 0)));
        testFontMap.insert(std::pair<char, Glyph>(')', Glyph(')', { 390, 158, 8, 26 }, 10, 0)));
        testFontMap.insert(std::pair<char, Glyph>('*', Glyph('*', { 74, 36, 16, 22 }, 18, 0)));
        testFontMap.insert(std::pair<char, Glyph>('+', Glyph('+', { 202, 124, 12, 22 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>(',', Glyph(',', { 66, 192, 4, 30 }, 6, 0)));
        testFontMap.insert(std::pair<char, Glyph>('-', Glyph('-', { 352, 158, 12, 18 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('.', Glyph('.', { 72, 192, 4, 26 }, 6, 0)));
        testFontMap.insert(std::pair<char, Glyph>('/', Glyph('/', { 134, 36, 12, 28 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('0', Glyph('0', { 240, 96, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('1', Glyph('1', { 310, 68, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('2', Glyph('2', { 302, 36, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('3', Glyph('3', { 428, 36, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('4', Glyph('4', { 288, 36, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('5', Glyph('5', { 204, 36, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('6', Glyph('6', { 352, 68, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('7', Glyph('7', { 478, 68, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('8', Glyph('8', { 162, 36, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('9', Glyph('9', { 170, 68, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>(':', Glyph(':', { 78, 192, 4, 26 }, 6, 0)));
        testFontMap.insert(std::pair<char, Glyph>(';', Glyph(';', { 60, 192, 4, 30 }, 6, 0)));
        testFontMap.insert(std::pair<char, Glyph>('<', Glyph('<', { 252, 124, 10, 26 }, 12, 0)));
        testFontMap.insert(std::pair<char, Glyph>('=', Glyph('=', { 338, 158, 12, 20 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('>', Glyph('>', { 240, 124, 10, 26 }, 12, 0)));
        testFontMap.insert(std::pair<char, Glyph>('?', Glyph('?', { 268, 96, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('@', Glyph('@', { 184, 96, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('A', Glyph('A', { 44, 124, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('B', Glyph('B', { 450, 96, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('C', Glyph('C', { 324, 68, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('D', Glyph('D', { 198, 68, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('E', Glyph('E', { 358, 36, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('F', Glyph('F', { 464, 68, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('G', Glyph('G', { 422, 96, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('H', Glyph('H', { 44, 96, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('I', Glyph('I', { 316, 36, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('J', Glyph('J', { 226, 68, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('K', Glyph('K', { 114, 96, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('L', Glyph('L', { 450, 68, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('M', Glyph('M', { 244, 2, 14, 26 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('N', Glyph('N', { 274, 36, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('O', Glyph('O', { 464, 96, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('P', Glyph('P', { 72, 124, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('Q', Glyph('Q', { 18, 36, 12, 30 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('R', Glyph('R', { 44, 68, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('S', Glyph('S', { 246, 36, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('T', Glyph('T', { 86, 68, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('U', Glyph('U', { 100, 96, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('V', Glyph('V', { 310, 96, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('W', Glyph('W', { 196, 2, 14, 26 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('X', Glyph('X', { 232, 36, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('Y', Glyph('Y', { 282, 68, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('Z', Glyph('Z', { 142, 68, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('[', Glyph('[', { 400, 158, 8, 26 }, 10, 0)));
        testFontMap.insert(std::pair<char, Glyph>('\\', Glyph('\\', {106, 36, 12, 28}, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>(']', Glyph(']', { 420, 158, 8, 26 }, 10, 0)));
        testFontMap.insert(std::pair<char, Glyph>('^', Glyph('^', { 456, 158, 12, 14 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('_', Glyph('_', { 264, 124, 8, 32 }, 10, 0)));
        testFontMap.insert(std::pair<char, Glyph>('`', Glyph('`', { 108, 192, 6, 10 }, 8, 0)));
        testFontMap.insert(std::pair<char, Glyph>('a', Glyph('a', { 226, 96, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('b', Glyph('b', { 240, 68, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('c', Glyph('c', { 408, 68, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('d', Glyph('d', { 156, 96, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('e', Glyph('e', { 212, 68, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('f', Glyph('f', { 436, 96, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('g', Glyph('g', { 66, 2, 12, 32 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('h', Glyph('h', { 330, 36, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('i', Glyph('i', { 100, 124, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('j', Glyph('j', { 52, 2, 12, 32 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('k', Glyph('k', { 268, 68, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('l', Glyph('l', { 86, 96, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('m', Glyph('m', { 452, 2, 14, 26 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('n', Glyph('n', { 176, 36, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('o', Glyph('o', { 218, 36, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('p', Glyph('p', { 38, 2, 12, 32 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('q', Glyph('q', { 94, 2, 12, 32 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('r', Glyph('r', { 372, 36, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('s', Glyph('s', { 484, 36, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('t', Glyph('t', { 442, 36, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('u', Glyph('u', { 30, 96, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('v', Glyph('v', { 394, 68, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('w', Glyph('w', { 212, 2, 14, 26 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('x', Glyph('x', { 100, 68, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('y', Glyph('y', { 80, 2, 12, 32 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('z', Glyph('z', { 128, 96, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('{', Glyph('{', { 216, 124, 10, 26 }, 12, 0)));
        testFontMap.insert(std::pair<char, Glyph>('|', Glyph('|', { 90, 192, 4, 26 }, 6, 0)));
        testFontMap.insert(std::pair<char, Glyph>('}', Glyph('}', { 228, 124, 10, 26 }, 12, 0)));
        testFontMap.insert(std::pair<char, Glyph>('~', Glyph('~', { 34, 158, 14, 18 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('', Glyph('', { 402, 124, 14, 18 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('', Glyph('', { 66, 158, 14, 18 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('', Glyph('', { 466, 124, 14, 18 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('', Glyph('', { 194, 158, 14, 18 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('', Glyph('', { 370, 124, 14, 18 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('', Glyph('', { 418, 124, 14, 18 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('', Glyph('', { 338, 124, 14, 18 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('', Glyph('', { 354, 124, 14, 18 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('', Glyph('', { 290, 158, 14, 18 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('', Glyph('', { 146, 158, 14, 18 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('', Glyph('', { 306, 158, 14, 18 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('', Glyph('', { 450, 124, 14, 18 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('', Glyph('', { 322, 158, 14, 18 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('', Glyph('', { 306, 124, 14, 18 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('', Glyph('', { 98, 158, 14, 18 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('', Glyph('', { 274, 124, 14, 18 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('', Glyph('', { 210, 158, 14, 18 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('', Glyph('', { 226, 158, 14, 18 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('', Glyph('', { 2, 158, 14, 18 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('', Glyph('', { 114, 158, 14, 18 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('', Glyph('', { 178, 158, 14, 18 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('', Glyph('', { 258, 158, 14, 18 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('', Glyph('', { 18, 158, 14, 18 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('', Glyph('', { 82, 158, 14, 18 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('', Glyph('', { 482, 124, 14, 18 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('', Glyph('', { 434, 124, 14, 18 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('', Glyph('', { 130, 158, 14, 18 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('', Glyph('', { 322, 124, 14, 18 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('', Glyph('', { 50, 158, 14, 18 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('', Glyph('', { 274, 158, 14, 18 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('', Glyph('', { 242, 158, 14, 18 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('', Glyph('', { 290, 124, 14, 18 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>(' ', Glyph(' ', { 162, 158, 14, 18 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('¡', Glyph('¡', { 380, 158, 8, 26 }, 10, 0)));
        testFontMap.insert(std::pair<char, Glyph>('¢', Glyph('¢', { 414, 36, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('£', Glyph('£', { 2, 36, 14, 26 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('¤', Glyph('¤', { 160, 124, 12, 24 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('¥', Glyph('¥', { 190, 36, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('¦', Glyph('¦', { 84, 192, 4, 26 }, 6, 0)));
        testFontMap.insert(std::pair<char, Glyph>('§', Glyph('§', { 120, 36, 12, 28 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('¨', Glyph('¨', { 46, 192, 12, 10 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('©', Glyph('©', { 468, 2, 14, 26 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('ª', Glyph('ª', { 14, 192, 10, 16 }, 12, 0)));
        testFontMap.insert(std::pair<char, Glyph>('«', Glyph('«', { 130, 124, 14, 22 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('¬', Glyph('¬', { 188, 124, 12, 22 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('­', Glyph('­', { 366, 158, 12, 18 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('®', Glyph('®', { 324, 2, 14, 26 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('¯', Glyph('¯', { 180, 2, 14, 26 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('°', Glyph('°', { 36, 192, 8, 16 }, 10, 0)));
        testFontMap.insert(std::pair<char, Glyph>('±', Glyph('±', { 30, 68, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('²', Glyph('²', { 494, 158, 10, 16 }, 12, 0)));
        testFontMap.insert(std::pair<char, Glyph>('³', Glyph('³', { 482, 158, 10, 16 }, 12, 0)));
        testFontMap.insert(std::pair<char, Glyph>('´', Glyph('´', { 116, 192, 6, 10 }, 8, 0)));
        testFontMap.insert(std::pair<char, Glyph>('µ', Glyph('µ', { 108, 2, 12, 32 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('¶', Glyph('¶', { 484, 2, 14, 26 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('·', Glyph('·', { 96, 192, 4, 18 }, 6, 0)));
        testFontMap.insert(std::pair<char, Glyph>('¸', Glyph('¸', { 448, 158, 6, 30 }, 8, 0)));
        testFontMap.insert(std::pair<char, Glyph>('¹', Glyph('¹', { 26, 192, 8, 16 }, 10, 0)));
        testFontMap.insert(std::pair<char, Glyph>('º', Glyph('º', { 2, 192, 10, 16 }, 12, 0)));
        testFontMap.insert(std::pair<char, Glyph>('»', Glyph('»', { 114, 124, 14, 22 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('¼', Glyph('¼', { 372, 2, 14, 26 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('½', Glyph('½', { 276, 2, 14, 26 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('¾', Glyph('¾', { 340, 2, 14, 26 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('¿', Glyph('¿', { 260, 36, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('À', Glyph('À', { 86, 124, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('Á', Glyph('Á', { 408, 96, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('Â', Glyph('Â', { 72, 68, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('Ã', Glyph('Ã', { 164, 2, 14, 26 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('Ä', Glyph('Ä', { 156, 68, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('Å', Glyph('Å', { 58, 96, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('Æ', Glyph('Æ', { 2, 2, 16, 26 }, 18, 0)));
        testFontMap.insert(std::pair<char, Glyph>('Ç', Glyph('Ç', { 60, 36, 12, 30 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('È', Glyph('È', { 254, 68, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('É', Glyph('É', { 338, 96, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('Ê', Glyph('Ê', { 344, 36, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('Ë', Glyph('Ë', { 2, 68, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('Ì', Glyph('Ì', { 422, 68, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('Í', Glyph('Í', { 366, 96, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('Î', Glyph('Î', { 436, 68, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('Ï', Glyph('Ï', { 72, 96, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('Ð', Glyph('Ð', { 356, 2, 14, 26 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('Ñ', Glyph('Ñ', { 292, 2, 14, 26 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('Ò', Glyph('Ò', { 386, 36, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('Ó', Glyph('Ó', { 380, 68, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('Ô', Glyph('Ô', { 184, 68, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('Õ', Glyph('Õ', { 420, 2, 14, 26 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('Ö', Glyph('Ö', { 170, 96, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('×', Glyph('×', { 174, 124, 12, 24 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('Ø', Glyph('Ø', { 92, 36, 12, 28 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('Ù', Glyph('Ù', { 380, 96, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('Ú', Glyph('Ú', { 296, 96, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('Û', Glyph('Û', { 478, 96, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('Ü', Glyph('Ü', { 58, 124, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('Ý', Glyph('Ý', { 114, 68, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('Þ', Glyph('Þ', { 492, 96, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('ß', Glyph('ß', { 16, 68, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('à', Glyph('à', { 128, 68, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('á', Glyph('á', { 338, 68, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('â', Glyph('â', { 394, 96, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('ã', Glyph('ã', { 308, 2, 14, 26 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('ä', Glyph('ä', { 254, 96, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('å', Glyph('å', { 296, 68, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('æ', Glyph('æ', { 20, 2, 16, 26 }, 18, 0)));
        testFontMap.insert(std::pair<char, Glyph>('ç', Glyph('ç', { 46, 36, 12, 30 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('è', Glyph('è', { 492, 68, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('é', Glyph('é', { 2, 124, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('ê', Glyph('ê', { 58, 68, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('ë', Glyph('ë', { 16, 124, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('ì', Glyph('ì', { 282, 96, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('í', Glyph('í', { 366, 68, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('î', Glyph('î', { 2, 96, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('ï', Glyph('ï', { 16, 96, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('ð', Glyph('ð', { 456, 36, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('ñ', Glyph('ñ', { 260, 2, 14, 26 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('ò', Glyph('ò', { 198, 96, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('ó', Glyph('ó', { 30, 124, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('ô', Glyph('ô', { 142, 96, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('õ', Glyph('õ', { 436, 2, 14, 26 }, 16, 0)));
        testFontMap.insert(std::pair<char, Glyph>('ö', Glyph('ö', { 212, 96, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('÷', Glyph('÷', { 146, 124, 12, 24 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('ø', Glyph('ø', { 148, 36, 12, 28 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('ù', Glyph('ù', { 400, 36, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('ú', Glyph('ú', { 324, 96, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('û', Glyph('û', { 470, 36, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('ü', Glyph('ü', { 352, 96, 12, 26 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('ý', Glyph('ý', { 150, 2, 12, 32 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('þ', Glyph('þ', { 136, 2, 12, 32 }, 14, 0)));
        testFontMap.insert(std::pair<char, Glyph>('ÿ', Glyph('ÿ', { 122, 2, 12, 32 }, 14, 0)));



        testFont = Font(testTextTexture, testFontMap);

        testTextWriter = TextWriter(&testFont);
        testTextWriter.SetRenderPosition({ 50, 120 });
        testTextWriter.GetRichText()->SetMonospacing(8);

        testTextWriter.SetRawText("* Just [c:00FF00]testing [c:Yellow]this system[/c] [c:0000FF]when \\[[c:Yellow]THE WORLD[/c]]\nattacks[/c].[/c]");
    }

    void ObjTestC::Update()
    {
        testTextWriter.Update();
    }

    void ObjTestC::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        
        target.draw(testTextWriter, states);
    }
}