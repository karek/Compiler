#ifndef PRINTER_HEADER
#define PRINTER_HEADER

#include "Absyn.H"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/* Certain applications may improve performance by changing the buffer size */
#define BUFFER_INITIAL 2000
/* You may wish to change _L_PAREN or _R_PAREN */
#define _L_PAREN '('
#define _R_PAREN ')'

class PrintAbsyn : public Visitor
{
 protected:
  int _n_, _i_;
  /* The following are simple heuristics for rendering terminals */
  /* You may wish to change them */
  void render(Char c);
  void render(String s);
void render(char* s);
  void indent(void);
  void backup(void);
 public:
  PrintAbsyn(void);
  ~PrintAbsyn(void);
  char* print(Visitable* v);

  void visitProgram(Program *p); /* abstract class */
  void visitProg(Prog *p);
  void visitTopDef(TopDef *p); /* abstract class */
  void visitFnDef(FnDef *p);
  void visitClsDef(ClsDef *p);
  void visitExtClsDef(ExtClsDef *p);
  void visitListTopDef(ListTopDef* p);
  void visitArg(Arg *p); /* abstract class */
  void visitAr(Ar *p);
  void visitListArg(ListArg* p);
  void visitClsElems(ClsElems *p); /* abstract class */
  void visitClsMethod(ClsMethod *p);
  void visitClsField(ClsField *p);
  void visitListClsElems(ListClsElems* p);
  void visitBlock(Block *p); /* abstract class */
  void visitBlk(Blk *p);
  void visitListStmt(ListStmt* p);
  void visitStmt(Stmt *p); /* abstract class */
  void visitEmpty(Empty *p);
  void visitBStmt(BStmt *p);
  void visitDecl(Decl *p);
  void visitAss(Ass *p);
  void visitIncr(Incr *p);
  void visitDecr(Decr *p);
  void visitRet(Ret *p);
  void visitVRet(VRet *p);
  void visitCond(Cond *p);
  void visitCondElse(CondElse *p);
  void visitWhile(While *p);
  void visitFor(For *p);
  void visitSExp(SExp *p);
  void visitItem(Item *p); /* abstract class */
  void visitNoInit(NoInit *p);
  void visitInit(Init *p);
  void visitListItem(ListItem* p);
  void visitBasicType(BasicType *p); /* abstract class */
  void visitInt(Int *p);
  void visitStr(Str *p);
  void visitBool(Bool *p);
  void visitVoid(Void *p);
  void visitFun(Fun *p);
  void visitTypeName(TypeName *p); /* abstract class */
  void visitBType(BType *p);
  void visitClsType(ClsType *p);
  void visitType(Type *p); /* abstract class */
  void visitArrayType(ArrayType *p);
  void visitNormalType(NormalType *p);
  void visitListType(ListType* p);
  void visitLVal(LVal *p); /* abstract class */
  void visitLvVar(LvVar *p);
  void visitLvTab(LvTab *p);
  void visitLvAttr(LvAttr *p);
  void visitExpr(Expr *p); /* abstract class */
  void visitEAttr(EAttr *p);
  void visitEMetCall(EMetCall *p);
  void visitECastNull(ECastNull *p);
  void visitEAt(EAt *p);
  void visitENewArr(ENewArr *p);
  void visitENewClArr(ENewClArr *p);
  void visitENewCls(ENewCls *p);
  void visitEVar(EVar *p);
  void visitELitInt(ELitInt *p);
  void visitELitTrue(ELitTrue *p);
  void visitELitFalse(ELitFalse *p);
  void visitEApp(EApp *p);
  void visitEString(EString *p);
  void visitNeg(Neg *p);
  void visitNot(Not *p);
  void visitEMul(EMul *p);
  void visitEAdd(EAdd *p);
  void visitERel(ERel *p);
  void visitEAnd(EAnd *p);
  void visitEOr(EOr *p);
  void visitListExpr(ListExpr* p);
  void visitAddOp(AddOp *p); /* abstract class */
  void visitPlus(Plus *p);
  void visitMinus(Minus *p);
  void visitMulOp(MulOp *p); /* abstract class */
  void visitTimes(Times *p);
  void visitDiv(Div *p);
  void visitMod(Mod *p);
  void visitRelOp(RelOp *p); /* abstract class */
  void visitLTH(LTH *p);
  void visitLE(LE *p);
  void visitGTH(GTH *p);
  void visitGE(GE *p);
  void visitEQU(EQU *p);
  void visitNE(NE *p);

  void visitInteger(Integer i);
  void visitDouble(Double d);
  void visitChar(Char c);
  void visitString(String s);
  void visitIdent(String s);
 protected:
  void inline bufAppend(const char* s)
  {
    int len = strlen(s);
    while (cur_ + len > buf_size)
    {
      buf_size *= 2; /* Double the buffer size */
      resizeBuffer();
    }
    for(int n = 0; n < len; n++)
    {
      buf_[cur_ + n] = s[n];
    }
    cur_ += len;
    buf_[cur_] = 0;
  }
  void inline bufAppend(const char c)
  {
    if (cur_ == buf_size)
    {
      buf_size *= 2; /* Double the buffer size */
      resizeBuffer();
    }
    buf_[cur_] = c;
    cur_++;
    buf_[cur_] = 0;
  }
  void inline bufAppend(String str)
  {
    const char* s = str.c_str();
    bufAppend(s);
  }
  void inline bufReset(void)
  {
    cur_ = 0;
    buf_size = BUFFER_INITIAL;
    resizeBuffer();
    memset(buf_, 0, buf_size);
  }
  void inline resizeBuffer(void)
  {
    char* temp = (char*) malloc(buf_size);
    if (!temp)
    {
      fprintf(stderr, "Error: Out of memory while attempting to grow buffer!\n");
      exit(1);
    }
    if (buf_)
    {
      strcpy(temp, buf_);
      free(buf_);
    }
    buf_ = temp;
  }
  char *buf_;
  int cur_, buf_size;
};



class ShowAbsyn : public Visitor
{
 public:
  ShowAbsyn(void);
  ~ShowAbsyn(void);
  char* show(Visitable* v);

  void visitProgram(Program *p); /* abstract class */
  void visitProg(Prog *p);
  void visitTopDef(TopDef *p); /* abstract class */
  void visitFnDef(FnDef *p);
  void visitClsDef(ClsDef *p);
  void visitExtClsDef(ExtClsDef *p);
  void visitListTopDef(ListTopDef* p);
  void visitArg(Arg *p); /* abstract class */
  void visitAr(Ar *p);
  void visitListArg(ListArg* p);
  void visitClsElems(ClsElems *p); /* abstract class */
  void visitClsMethod(ClsMethod *p);
  void visitClsField(ClsField *p);
  void visitListClsElems(ListClsElems* p);
  void visitBlock(Block *p); /* abstract class */
  void visitBlk(Blk *p);
  void visitListStmt(ListStmt* p);
  void visitStmt(Stmt *p); /* abstract class */
  void visitEmpty(Empty *p);
  void visitBStmt(BStmt *p);
  void visitDecl(Decl *p);
  void visitAss(Ass *p);
  void visitIncr(Incr *p);
  void visitDecr(Decr *p);
  void visitRet(Ret *p);
  void visitVRet(VRet *p);
  void visitCond(Cond *p);
  void visitCondElse(CondElse *p);
  void visitWhile(While *p);
  void visitFor(For *p);
  void visitSExp(SExp *p);
  void visitItem(Item *p); /* abstract class */
  void visitNoInit(NoInit *p);
  void visitInit(Init *p);
  void visitListItem(ListItem* p);
  void visitBasicType(BasicType *p); /* abstract class */
  void visitInt(Int *p);
  void visitStr(Str *p);
  void visitBool(Bool *p);
  void visitVoid(Void *p);
  void visitFun(Fun *p);
  void visitTypeName(TypeName *p); /* abstract class */
  void visitBType(BType *p);
  void visitClsType(ClsType *p);
  void visitType(Type *p); /* abstract class */
  void visitArrayType(ArrayType *p);
  void visitNormalType(NormalType *p);
  void visitListType(ListType* p);
  void visitLVal(LVal *p); /* abstract class */
  void visitLvVar(LvVar *p);
  void visitLvTab(LvTab *p);
  void visitLvAttr(LvAttr *p);
  void visitExpr(Expr *p); /* abstract class */
  void visitEAttr(EAttr *p);
  void visitEMetCall(EMetCall *p);
  void visitECastNull(ECastNull *p);
  void visitEAt(EAt *p);
  void visitENewArr(ENewArr *p);
  void visitENewClArr(ENewClArr *p);
  void visitENewCls(ENewCls *p);
  void visitEVar(EVar *p);
  void visitELitInt(ELitInt *p);
  void visitELitTrue(ELitTrue *p);
  void visitELitFalse(ELitFalse *p);
  void visitEApp(EApp *p);
  void visitEString(EString *p);
  void visitNeg(Neg *p);
  void visitNot(Not *p);
  void visitEMul(EMul *p);
  void visitEAdd(EAdd *p);
  void visitERel(ERel *p);
  void visitEAnd(EAnd *p);
  void visitEOr(EOr *p);
  void visitListExpr(ListExpr* p);
  void visitAddOp(AddOp *p); /* abstract class */
  void visitPlus(Plus *p);
  void visitMinus(Minus *p);
  void visitMulOp(MulOp *p); /* abstract class */
  void visitTimes(Times *p);
  void visitDiv(Div *p);
  void visitMod(Mod *p);
  void visitRelOp(RelOp *p); /* abstract class */
  void visitLTH(LTH *p);
  void visitLE(LE *p);
  void visitGTH(GTH *p);
  void visitGE(GE *p);
  void visitEQU(EQU *p);
  void visitNE(NE *p);

  void visitInteger(Integer i);
  void visitDouble(Double d);
  void visitChar(Char c);
  void visitString(String s);
  void visitIdent(String s);
 protected:
  void inline bufAppend(const char* s)
  {
    int len = strlen(s);
    while (cur_ + len > buf_size)
    {
      buf_size *= 2; /* Double the buffer size */
      resizeBuffer();
    }
    for(int n = 0; n < len; n++)
    {
      buf_[cur_ + n] = s[n];
    }
    cur_ += len;
    buf_[cur_] = 0;
  }
  void inline bufAppend(const char c)
  {
    if (cur_ == buf_size)
    {
      buf_size *= 2; /* Double the buffer size */
      resizeBuffer();
    }
    buf_[cur_] = c;
    cur_++;
    buf_[cur_] = 0;
  }
  void inline bufAppend(String str)
  {
    const char* s = str.c_str();
    bufAppend(s);
  }
  void inline bufReset(void)
  {
    cur_ = 0;
    buf_size = BUFFER_INITIAL;
    resizeBuffer();
    memset(buf_, 0, buf_size);
  }
  void inline resizeBuffer(void)
  {
    char* temp = (char*) malloc(buf_size);
    if (!temp)
    {
      fprintf(stderr, "Error: Out of memory while attempting to grow buffer!\n");
      exit(1);
    }
    if (buf_)
    {
      strcpy(temp, buf_);
      free(buf_);
    }
    buf_ = temp;
  }
  char *buf_;
  int cur_, buf_size;
};




#endif

