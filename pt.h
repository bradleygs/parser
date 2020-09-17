/*
 * pt.h
 */

#ifndef PT_H_
#define PT_H_

#include <iostream>
#include <vector>
#include <map>
#include <string>

using std::vector;
using std::map;
using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

#include "parse.h"
#include "lex.h"

class Pt {
protected:
	int	linenum;
	Pt	*left;
	Pt	*right;

public:
	Pt(int linenum, Pt *l = 0, Pt *r = 0)
		: linenum(linenum), left(l), right(r) {}

	virtual ~Pt() {
		delete left;
		delete right;
	}
  int maxDepth(Pt *node) {
    if (node == NULL) 
      return 0;
      int lDepth = maxDepth(node->left);
      int rDepth = maxDepth(node->right);
      if (lDepth > rDepth) 
        return lDepth + 1;
      else 
        return rDepth + 1;
  }
    void postOrder(Pt *node) {
        if (node == NULL) 
            return;
        postOrder(node->left);
        postOrder(node->right);
        cout << node->GetLineNumber() << endl;
    }

	int GetLineNumber() const { return linenum; }

    virtual bool isPlus() const { return false; }
    
    int plusCount() const {
        int pCount = 0;
        if (left) 
            pCount += left->plusCount();
        
        if (right) 
            pCount += right->plusCount();
        
        if (isPlus()) {
            pCount++;
        }
        return pCount;
    }
            
    
    virtual bool isEq() const { return false; }
    int eqCount() const {
        int eCount = 0;
        if (left) 
            eCount += left->eqCount();
        if (right)
            eCount += right->eqCount();
        if (isEq()) {
            eCount++;
        }
        return eCount;
    }
	virtual bool isIdent() const { return false; }
	virtual bool isVar() const { return false; }
	virtual string getId() const { return ""; }

};

class StmtList : public Pt {
public:
	StmtList(Pt *l, Pt *r) : Pt(0, l, r) {}
};

class Print : public Pt {
public:
	Print(int line, Pt *e) : Pt(line, e) {}
};

class Println : public Pt {
public:
    Println(int line, Pt *e) : Pt(line, e) {}
};

class Repeat : public Pt {
public:
    Repeat(int line, Pt *e, Pt *s) : Pt(line, e, s) {}

};

class Assign : public Pt {
public:
    Assign(int line, Pt *l, Pt *r) : Pt(line, l, r) {}
    bool isEq() const { return true;}

};

class PlusExpr : public Pt {
public:
    PlusExpr(int line, Pt *l, Pt *r) : Pt(line, l, r) {}
    bool isPlus() const { return true;}

};

class MinusExpr : public Pt {
public:
    MinusExpr(int line, Pt *l, Pt *r) : Pt(line, l, r) {}

};

class TimesExpr : public Pt {
public:
    TimesExpr(int line, Pt *l, Pt *r) : Pt(line, l, r) {}

};

class DivideExpr : public Pt {
public:
    DivideExpr(int line, Pt *l, Pt *r) : Pt(line, l, r) {}
// FIXME add code

};

class IConst : public Pt {
	int val;

public:
	IConst(Tok& t) : Pt(t.GetLinenum()) {
		val = stoi(t.GetLexeme());
	}
};

class SConst : public Pt {
	string val;

public:
	SConst(Tok& t) : Pt(t.GetLinenum()) {
		val = t.GetLexeme();
	}
};

class Ident : public Pt {
  string val;

public:
  Ident(Tok& t) : Pt(t.GetLinenum()) {
    val = t.GetLexeme();
  }
};

#endif /* PT_H_ */
