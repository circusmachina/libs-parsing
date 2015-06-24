{ sourceparsers.inc: A class to parse a source stream using a language
    definition and symbol tables, into an intermediate code stream.

  This file is part of parsing.pp, a library of basic and useful parser classes.

  This program is free software: you can redistribute it and/or modify it
  under the terms of the GNU General Public License as published by the
  Free Software Foundation; either version 3 of the License or, at your
  option, any later version.

  This program is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABLITY
  or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
  License for more details.

  You should have received a copy of the GNU General Public License along
  with this program.  If not, see <http://www.gnu.org/licenses/>.
}
{$IFDEF ReadInterface}
{ This class represents a parser that uses a language definition to parse an
  arbitrary source stream into intermediate code.  Symbols (identifiers and
  constants) that are encountered by the parser are destined to be entered into
  its symbol tables.

  You will likely not create a direct instance of this class, as calling
  its @code(parse) method does not do much that is useful.  Instead, you will
  derive a custom class from this one.
}
type ASourceParser = class(ASymbolParser)
  protected
    { Refers to the stream used by the parser for output. }
    MyOutput: AStream;

  public
    { Initializer }
    function init: boolean; override;

    { Determine whether or not the parser is ready to parse.

      This method builds on the behavior inherited from
      @link(ASymbolParser.readyToParse).  It calls the inherited routine
      and, if that routine returns @true to indicate all is well, it checks to
      determine whether @link(ASourceParser.Output Self.Output) is @nil,
      indicating that no output stream has been defined for the parser.  If not,
      it attempts to borrow the reference from the parent, if it is available.

      To parse successfully, an output stream must be provided to the parser
      before parsing begins.  To set the output stream used by the parser,
      call @link(ASourceParser.SetOutput).  This method will return @false if no
      output stream has been provided and it is unable to borrow the reference
      of a parent.

      @return(@true if the parser is ready to parse; @false if not.)
    }
    function readyToParse: boolean; override;

    // Properties --------------------------------------------------------------
    { Retrieve a reference to the output stream used by the parser.

      This is the stream to which syntax-checked code is written and will most
      likely represent an intermediate code stream of some kind.

      The caller should NOT free the reference returned by this routine.
    }
    function Output: AStream; virtual;

    { Set the output stream used by the parser.

      In most cases, @code(Dest) will refer to a binary stream which is used
      to capture raw tokens as they are sucessfully parsed from a source
      stream.

      @return(The previous value of @link(ASourceParser.Output).)
    }
    function SetOutput(const Dest: AStream): AStream; virtual;
end;
{$ENDIF}
{$IFDEF ReadImplementation}
// Initializer
function ASourceParser.init: boolean;

begin
  result := inherited init;

  if result then
  begin
    MyOutput := nil;
  end;
end;

// Determine whether or not the parser is ready to parse
function ASourceParser.readyToParse: boolean;

begin
  // Call the inherited routine first
  result := inherited readyToParse;

  if result then
  begin
    // Check to see whether we have a valid output stream
    if MyOutput = nil then
      // Check to see if we can inherit from the parent
      if (MyParent <> nil) and (MyParent is ASourceParser) then
        MyOutput := ASourceParser(MyParent).Output;

    result := MyOutput <> nil;
  end;
end;

// Properties ------------------------------------------------------------------
// Retrieve a reference to the output stream
function ASourceParser.Output: AStream;

begin
  Result := MyOutput;
end;

// Set the output stream to use
function ASourceParser.SetOutput(const Dest: AStream): AStream;

begin
  // Return the old value
  Result := MyOutput;

  MyOutput := Dest;
end;
{$ENDIF}

