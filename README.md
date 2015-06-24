**parsing.pp** - A library of basic parser classes useful in larger projects.  
Copyright (C) 2014-2015 [Michael Malicoat][Author].  
[Home page][] | [Source][] | [Source documentation][] |
[Bug tracker][]

## Overview ##
The parsing library found along with this file is designed to provide an
object-oriented approach to a recursive-descent parser.  While there are many 
arguments for and against recursive-descent parsers *vs.* table-driven parsers, 
the fact remains that recursive-descent parsers are easier to implement, which 
is why the design and implementation of such a parser is often used as an 
educational tool.  But recursive-descent parsers are not limited to the 
educational environment; they also enjoy wide use in several 
["real-world" situations][1].  Although [parsing.pp][Home page] codes for a 
recursive-descent parser, an examination of the source should reveal that it is
written in such a way that constructing a table-driven parser should require 
fairly little effort on the part of the programmer who desires one.

The library defines several classes to handle:

* [lexer definition][AParsedLanguage]
* [source file scanning][AScanner]
* [tokenizing][AToken]
* [parsing][AParser]
* [symbols][ASymbol] and [symbol tables][ASymbolTable]

## How to use the parsing library ##
This file is not meant to be a reference on how to build a parser, although you
can learn how this one is built by looking at the source code and associated
documentation.  There are several books available that can take you through the
design and implementation of a parser; the book 
[_Writing Compilers and Interpreters_][2] by Ronald Mak helped to shape the
early design of the parser contained here.

A practical example of how the parsing library can be used to parse a language
can be found in the [series of articles][3] I've written that deal with writing 
a parser to parse the command-line arguments passed to a program.  You can also
refer to the [source][libs-linearc] for [LinearC][] to see how it all comes 
together.

## License ##
This program is free software: you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation; either version 3 of the License or, at your option, any later 
version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABLITY or FITNESS FOR A
PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program.  If not, see <http://www.gnu.org/licenses/>.

## References ##
_(Not visible in the parsed HTML output because they've turned into the 
various links used in the text above.)_

[Author]: http://www.circusmachina.com/gladius/Profiles/Michael
[Home page]: http://docs.circusmachina.com/libs/parsing/
[Source]: https://github.com/circusmachina/libs-parsing
[Source documentation]: http://docs.circusmachina.com/libs/parsing/
[Bug tracker]: http://monkeywrench.circusmachina.com

[PasDoc]: http://pasdoc.sourceforge.net
[GraphViz]: http://www.graphviz.org

[1]: https://developer.mozilla.org/en-US/docs/Mozilla/Projects/SpiderMonkey/Internals
[2]: http://www.amazon.com/dp/B000V5WH5K/
[3]: http://www.circusmachina.com/gladius/Tags/LinearC

[libs-linearc]: https://github.com/circusmachina/libs-linearc
[LinearC]: http://docs.circusmachina.com/libs/linearc/html/

[AParsedLanguage]: http://docs.circusmachina.com/libs/parsing/html/parsing.AParsedLanguage.html
[AScanner]: http://docs.circusmachina.com/libs/parsing/html/parsing.AScanner.html
[AToken]: http://docs.circusmachina.com/libs/parsing/html/parsing.AToken.html
[AParser]: http://docs.circusmachina.com/libs/parsing/html/parsing.AParser.html
[ASymbol]: http://docs.circusmachina.com/libs/parsing/html/parsing.ASymbol.html
[ASymbolTable]: http://docs.circusmachina.com/libs/parsing/html/parsing.ASymbolTable.html

