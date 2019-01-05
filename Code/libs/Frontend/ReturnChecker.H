#ifndef RETURNCHECKER_HEADER
#define RETURNCHECKER_HEADER
/* You might want to change the above name. */

#include "../Absyn.H"
#include "../Environment.H"

class ReturnChecker : public Visitor {
   private:
    bool wasReturn;
    Env* env;

   public:
    void checkReturns(Visitable* v, Env* e);

    void visitProgram(Program* p);
    void visitTopDef(TopDef* p);
    void visitArg(Arg* p);
    void visitClsElems(ClsElems* p);
    void visitBlock(Block* p);
    void visitStmt(Stmt* p);
    void visitItem(Item* p);
    void visitBasicType(BasicType* p);
    void visitTypeName(TypeName* p);
    void visitType(Type* p);
    void visitLVal(LVal* p);
    void visitExpr(Expr* p);
    void visitAddOp(AddOp* p);
    void visitMulOp(MulOp* p);
    void visitRelOp(RelOp* p);
    void visitProg(Prog* p);
    void visitFnDef(FnDef* p);
    void visitClsDef(ClsDef* p);
    void visitExtClsDef(ExtClsDef* p);
    void visitAr(Ar* p);
    void visitClsMethod(ClsMethod* p);
    void visitClsField(ClsField* p);
    void visitBlk(Blk* p);
    void visitEmpty(Empty* p);
    void visitBStmt(BStmt* p);
    void visitDecl(Decl* p);
    void visitNoInit(NoInit* p);
    void visitInit(Init* p);
    void visitAss(Ass* p);
    void visitIncr(Incr* p);
    void visitDecr(Decr* p);
    void visitRet(Ret* p);
    void visitVRet(VRet* p);
    void visitCond(Cond* p);
    void visitCondElse(CondElse* p);
    void visitWhile(While* p);
    void visitFor(For* p);
    void visitSExp(SExp* p);
    void visitInt(Int* p);
    void visitStr(Str* p);
    void visitBool(Bool* p);
    void visitVoid(Void* p);
    void visitFun(Fun* p);
    void visitBType(BType* p);
    void visitClsType(ClsType* p);
    void visitArrayType(ArrayType* p);
    void visitNormalType(NormalType* p);
    void visitLvVar(LvVar* p);
    void visitLvTab(LvTab* p);
    void visitLvAttr(LvAttr* p);
    void visitEAttr(EAttr* p);
    void visitEMetCall(EMetCall* p);
    void visitECastNull(ECastNull* p);
    void visitEAt(EAt* p);
    void visitENewArr(ENewArr* p);
    void visitENewClArr(ENewClArr* p);
    void visitENewCls(ENewCls* p);
    void visitEVar(EVar* p);
    void visitELitInt(ELitInt* p);
    void visitELitTrue(ELitTrue* p);
    void visitELitFalse(ELitFalse* p);
    void visitEApp(EApp* p);
    void visitEString(EString* p);
    void visitNeg(Neg* p);
    void visitNot(Not* p);
    void visitEMul(EMul* p);
    void visitEAdd(EAdd* p);
    void visitERel(ERel* p);
    void visitEAnd(EAnd* p);
    void visitEOr(EOr* p);
    void visitPlus(Plus* p);
    void visitMinus(Minus* p);
    void visitTimes(Times* p);
    void visitDiv(Div* p);
    void visitMod(Mod* p);
    void visitLTH(LTH* p);
    void visitLE(LE* p);
    void visitGTH(GTH* p);
    void visitGE(GE* p);
    void visitEQU(EQU* p);
    void visitNE(NE* p);
    void visitListTopDef(ListTopDef* p);
    void visitListArg(ListArg* p);
    void visitListClsElems(ListClsElems* p);
    void visitListStmt(ListStmt* p);
    void visitListItem(ListItem* p);
    void visitListType(ListType* p);
    void visitListExpr(ListExpr* p);

    void visitInteger(Integer x);
    void visitChar(Char x);
    void visitDouble(Double x);
    void visitString(String x);
    void visitIdent(Ident x);
};

#endif
