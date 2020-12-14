/*
 * Tai Smith
 * 
 * October 3, 2020
 *
 * C++ Program that reads in a file and outputs the lexemes and tokens
 *
 *
 *
*/
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <vector>

using namespace std;

//create enum to call in parse.cpp - was not working for me
/*enum token_type {
    SUB_OP, ADD_OP, MULT_OP, DIV_OP, LEFT_BRAC, RIGHT_BRAC,
    LEFT_PAREN, RIGHT_PAREN,
    MOD_OP, EQUAL_OP, SEMICOLON, COMMA, KEYWORD, IDENTIFIER;

};*/

struct token {
    string lexeme;
    //true_type type;
};

int isKeyword(char range[]) {
  char keywords[32][10] = {"auto", "break", "case", "char", "const", "continue",
                           "default",
                           "do", "double", "else", "enum", "extern", "float", "for", "goto",
                           "if", "int", "long", "register", "return", "short", "signed",
                           "sizeof", "static", "struct", "switch", "typedef", "union",
                           "unsigned", "void", "volatile", "while"};
  int i, flag = 0;

  for (i = 0; i < 32; ++i) {
    if (strcmp(keywords[i], range) == 0) {
      flag = 1;
      break;
    }
  }
  return flag;
}

int main() {
  vector<token> tokens;   //store tokens for parser
  char ch, range[15], operators[] = "+-*/%={}();,";       // instantiate operators
  ifstream fin("test2.txt");
  int i, j = 0;
  if (!fin.is_open()) {
    cout << "error while opening the file\n";
    exit(0);
  }
  while (!fin.eof()) {
    token next_token;
    ch = fin.get();
    if (isalnum(ch)) {
      range[j++] = ch;
    }
      // if the character isn't alnum and j isn't 0 then we're at the end of the identifer
    else if (j != 0) {
      range[j] = '\0';
      j = 0;
      if (isKeyword(range)) {
        cout << "Lexeme is: " << range << " | " << "Token is: keyword\n";
      } else {
        cout << "Lexeme is: " << range << " | " << "Token is: identifier\n";
      }
    }
    if (ch == '-') {   //differentiate between operators
      next_token.lexeme = "-";
      //token_type = SUB_OP;
      cout << "Lexeme is: " << ch << " | " << " Token is SUB_OP\n";
    } else if (ch == '+') {
      next_token.lexeme = "+";
      // nextToken.t = ADD_OP;
      cout << "Lexeme is: " << ch << " | " << " Token is: ADD_OP\n";
    } else if (ch == '*') {
      next_token.lexeme = "*";
      //  nextToken.t = ADD_OP;
      cout << "Lexeme is: " << ch << " | " << " Token is: MULT_OP\n";
    } else if (ch == '/') {
      next_token.lexeme = "/";
      cout << "Lexeme is: " << ch << " | " << " Token is: DIV_OP\n";
    } else if (ch == '{') {
      next_token.lexeme = "{";
      cout << "Lexeme is: " << ch << " | " << " Token is: LEFT_PAREN\n";
    } else if (ch == '}') {
      next_token.lexeme = "}";
      cout << "Lexeme is: " << ch << " | " << " Token is: RIGHT_PAREN\n";
    } else if (ch == '(') {
      next_token.lexeme = "(";
      cout << "Lexeme is: " << ch << " | " << " Token is: LEFT_PAREN\n";
    } else if (ch == ')') {
    next_token.lexeme = ")";
      cout << "Lexeme is: " << ch << " | " << " Token is: RIGHT_PAREN\n";
    } else if (ch == '%') {
      next_token.lexeme = "%";
      cout << "Lexeme is: " << ch << " | " << "Token is: MOD_OP\n";
    } else if (ch == '=') {
      next_token.lexeme = "=";
      cout << "Lexeme is: " << ch << " | " << " Token is: EQUAL_OP\n";
    } else if (ch == ';') {
      next_token.lexeme = ";";
      cout << "Lexeme is: " << ch << " | " << " Token is: SEMICOLON\n";
    } else if (ch == ',') {
      next_token.lexeme = ",";
      cout << "Lexeme is: " << ch << " | " << " Token is: COMMA\n";
    }
    tokens.push_back(next_token);
  }
  fin.close();
  return 0;
}


