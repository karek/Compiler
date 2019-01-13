/*** BNFC-Generated Visitor Design Pattern CodeCreator. ***/
/* This implements the common visitor design pattern.
   Note that this method uses Visitor-traversal of lists, so
   List->accept() does NOT traverse the list. This allows different
   algorithms to use context information differently. */

#include <iostream>
#include <sstream>
#include "CodeCreator.H"

using namespace std;

void CodeCreator::visitProgram(Program *t) {}      // abstract class
void CodeCreator::visitTopDef(TopDef *t) {}        // abstract class
void CodeCreator::visitArg(Arg *t) {}              // abstract class
void CodeCreator::visitClsElems(ClsElems *t) {}    // abstract class
void CodeCreator::visitBlock(Block *t) {}          // abstract class
void CodeCreator::visitStmt(Stmt *t) {}            // abstract class
void CodeCreator::visitItem(Item *t) {}            // abstract class
void CodeCreator::visitBasicType(BasicType *t) {}  // abstract class
void CodeCreator::visitTypeName(TypeName *t) {}    // abstract class
void CodeCreator::visitType(Type *t) {}            // abstract class
void CodeCreator::visitLVal(LVal *t) {}            // abstract class
void CodeCreator::visitExpr(Expr *t) {}            // abstract class
void CodeCreator::visitAddOp(AddOp *t) {}          // abstract class
void CodeCreator::visitMulOp(MulOp *t) {}          // abstract class
void CodeCreator::visitRelOp(RelOp *t) {}          // abstract class

void CodeCreator::create(Visitable *v, Env *e) {
    env = e;
    v->accept(this);
}

void CodeCreator::deleteInstr() {
    for (int i = 0; i < instructions.size(); i++) {
        delete instructions[i];
    }
    instructions.clear();
}

void CodeCreator::printAllInstrs() {
    for (int i = 0; i < instructions.size(); i++) {
        if (!instructions[i]->isLabel())
            cerr << "\t";
        cerr << instructions[i]->toStr();
    }
}

void CodeCreator::emit(Instruction *instr) {
    instructions.push_back(instr);
}

void CodeCreator::visitProg(Prog *prog) {
    /* Code For Prog Goes Here */

    prog->listtopdef_->accept(this);
}

void CodeCreator::visitFnDef(FnDef *fndef) {
    /* Code For FnDef Goes Here */

    i = new Label(fndef->ident_);
    emit(i);
    i = new Push(Addr(Reg::EBP).toStr());
    emit(i);
    i = new Mov(Addr(Reg::ESP).toStr(), Addr(Reg::EBP).toStr());
    emit(i);

    stringstream ss;
    ss << "$" << env->getLocalsCnt(fndef->ident_)*MULTIPLIER;
    i = new Sub(ss.str(), Addr(Reg::ESP).toStr());
    emit(i);


    nrLoc = -1;
    fndef->type_->accept(this);
    visitIdent(fndef->ident_);
    fndef->listarg_->accept(this);


    vector<pair<string, TType>> fargs = env->getArgs(fndef->ident_);
    env->beginBlock();  // Arguments vars
    for (int i = fargs.size() - 1; i >= 0; i--) {
        int pos = i + 2;
        env->addVarToCurScope(fargs[i].first, fargs[i].second, pos);
    }
    fndef->block_->accept(this);
    env->endBlock();
}

void CodeCreator::visitClsDef(ClsDef *clsdef) {
    /* Code For ClsDef Goes Here */

    visitIdent(clsdef->ident_);
    clsdef->listclselems_->accept(this);
}

void CodeCreator::visitExtClsDef(ExtClsDef *extclsdef) {
    /* Code For ExtClsDef Goes Here */

    visitIdent(extclsdef->ident_1);
    visitIdent(extclsdef->ident_2);
    extclsdef->listclselems_->accept(this);
}

void CodeCreator::visitAr(Ar *ar) {
    /* Code For Ar Goes Here */

    ar->type_->accept(this);
    visitIdent(ar->ident_);
}

void CodeCreator::visitClsMethod(ClsMethod *clsmethod) {
    /* Code For ClsMethod Goes Here */

    clsmethod->type_->accept(this);
    visitIdent(clsmethod->ident_);
    clsmethod->listarg_->accept(this);
    clsmethod->block_->accept(this);
}

void CodeCreator::visitClsField(ClsField *clsfield) {
    /* Code For ClsField Goes Here */

    clsfield->type_->accept(this);
    visitIdent(clsfield->ident_);
}

void CodeCreator::visitBlk(Blk *blk) {
    /* Code For Blk Goes Here */

    blk->liststmt_->accept(this);
}

void CodeCreator::visitEmpty(Empty *empty) {
    /* Code For Empty Goes Here */
}

void CodeCreator::visitBStmt(BStmt *bstmt) {
    /* Code For BStmt Goes Here */
    env->beginBlock();
    bstmt->block_->accept(this);
    env->endBlock();
}

void CodeCreator::visitDecl(Decl *decl) {
    /* Code For Decl Goes Here */

    decl->type_->accept(this);
    decl->listitem_->accept(this);
}

void CodeCreator::visitAss(Ass *ass) {
    /* Code For Ass Goes Here */

    ass->expr_->accept(this);
    i = new Pop(Addr(Reg::ECX).toStr());
    emit(i);
    ass->lval_->accept(this);
    i = new Mov(Addr(Reg::ECX).toStr(), Addr(Reg::EAX).toStr(true));
    emit(i);


}

void CodeCreator::visitIncr(Incr *incr) {
    /* Code For Incr Goes Here */
    incr->lval_->accept(this);
    i = new Inc(Addr(Reg::EAX).toStr(true));
    emit(i);
}

void CodeCreator::visitDecr(Decr *decr) {
    /* Code For Decr Goes Here */
    decr->lval_->accept(this);
    i = new Dec(Addr(Reg::EAX).toStr(true));
    emit(i);
}

void CodeCreator::emitRetSequence() {
    i = new Mov(Addr(Reg::EBP).toStr(), Addr(Reg::ESP).toStr());
    emit(i);
    i = new Pop(Addr(Reg::EBP).toStr());
    emit(i);
    i = new RetC();
    emit(i);
}

void CodeCreator::visitRet(Ret *ret) {
    /* Code For Ret Goes Here */
    // Todo: Strings?

    ret->expr_->accept(this);
    i = new Pop(Addr(Reg::EAX).toStr());
    emit(i);

    emitRetSequence();    
}

void CodeCreator::visitVRet(VRet *vret) {
    /* Code For VRet Goes Here */
    emitRetSequence();
}

void CodeCreator::visitCond(Cond *cond) {
    /* Code For Cond Goes Here */

    cond->expr_->accept(this);
    cond->stmt_->accept(this);
}

void CodeCreator::visitCondElse(CondElse *condelse) {
    /* Code For CondElse Goes Here */

    condelse->expr_->accept(this);
    condelse->stmt_1->accept(this);
    condelse->stmt_2->accept(this);
}

void CodeCreator::visitWhile(While *w) {
    /* Code For While Goes Here */

    w->expr_->accept(this);
    w->stmt_->accept(this);
}

void CodeCreator::visitFor(For *f) {
    /* Code For For Goes Here */

    f->type_->accept(this);
    visitIdent(f->ident_1);
    visitIdent(f->ident_2);
    f->stmt_->accept(this);
}

void CodeCreator::visitSExp(SExp *sexp) {
    /* Code For SExp Goes Here */

    sexp->expr_->accept(this);
}

void CodeCreator::emitLocalVar(string ident) {
    env->addVarToCurScope(ident, declType, nrLoc);
    nrLoc--;
}

void CodeCreator::visitNoInit(NoInit *noinit) {
    /* Code For NoInit Goes Here */
    // TODO Strings
    
    emitLocalVar(noinit->ident_);
    visitIdent(noinit->ident_);

    int pos = env->getPos(noinit->ident_);
    i = new Mov("$0", Addr(Reg::EBP, pos).toStr());
    emit(i);
}

void CodeCreator::visitInit(Init *init) {
    /* Code For Init Goes Here */

    emitLocalVar(init->ident_);
    visitIdent(init->ident_);
    init->expr_->accept(this);

    i = new Pop(Addr(Reg::EAX).toStr());
    emit(i);
    int pos = env->getPos(init->ident_);
    i = new Mov(Addr(Reg::EAX).toStr(), Addr(Reg::EBP, pos).toStr());
    emit(i);

}

void CodeCreator::visitInt(Int *i) {
    /* Code For Int Goes Here */
    declType = TType(vType::tInt);
}

void CodeCreator::visitStr(Str *str) {
    /* Code For Str Goes Here */
    declType = TType(vType::tStr);
}

void CodeCreator::visitBool(Bool *b) {
    /* Code For Bool Goes Here */
    declType = TType(vType::tBool);
}

void CodeCreator::visitVoid(Void *v) {
    /* Code For Void Goes Here */
    declType = TType(vType::tVoid);
}

void CodeCreator::visitFun(Fun *fun) {
    /* Code For Fun Goes Here */

    fun->type_->accept(this);
    fun->listtype_->accept(this);
}

void CodeCreator::visitBType(BType *btype) {
    /* Code For BType Goes Here */

    btype->basictype_->accept(this);
}

void CodeCreator::visitClsType(ClsType *clstype) {
    /* Code For ClsType Goes Here */

    visitIdent(clstype->ident_);
}

void CodeCreator::visitArrayType(ArrayType *arraytype) {
    /* Code For ArrayType Goes Here */

    arraytype->typename_->accept(this);
}

void CodeCreator::visitNormalType(NormalType *normaltype) {
    /* Code For NormalType Goes Here */

    normaltype->typename_->accept(this);
}

void CodeCreator::visitLvVar(LvVar *lvvar) {
    /* Code For LvVar Goes Here */
    int pos = env->getPos(lvvar->ident_) * MULTIPLIER;

    stringstream ss;
    ss <<  pos << "(, \%ebp, 1)";

    i = new Lea(ss.str(), Addr(Reg::EAX).toStr());
    emit(i);
    visitIdent(lvvar->ident_);
}

void CodeCreator::visitLvTab(LvTab *lvtab) {
    /* Code For LvTab Goes Here */

    lvtab->expr_1->accept(this);
    lvtab->expr_2->accept(this);
}

void CodeCreator::visitLvAttr(LvAttr *lvattr) {
    /* Code For LvAttr Goes Here */

    lvattr->expr_->accept(this);
    visitIdent(lvattr->ident_);
}

void CodeCreator::visitEAttr(EAttr *eattr) {
    /* Code For EAttr Goes Here */

    eattr->expr_->accept(this);
    visitIdent(eattr->ident_);
}

void CodeCreator::visitEMetCall(EMetCall *emetcall) {
    /* Code For EMetCall Goes Here */

    emetcall->expr_->accept(this);
    visitIdent(emetcall->ident_);
    emetcall->listexpr_->accept(this);
}

void CodeCreator::visitECastNull(ECastNull *ecastnull) {
    /* Code For ECastNull Goes Here */

    visitIdent(ecastnull->ident_);
}

void CodeCreator::visitEAt(EAt *eat) {
    /* Code For EAt Goes Here */

    eat->expr_1->accept(this);
    eat->expr_2->accept(this);
}

void CodeCreator::visitENewArr(ENewArr *enewarr) {
    /* Code For ENewArr Goes Here */

    enewarr->basictype_->accept(this);
    enewarr->expr_->accept(this);
}

void CodeCreator::visitENewClArr(ENewClArr *enewclarr) {
    /* Code For ENewClArr Goes Here */

    visitIdent(enewclarr->ident_);
    enewclarr->expr_->accept(this);
}

void CodeCreator::visitENewCls(ENewCls *enewcls) {
    /* Code For ENewCls Goes Here */

    visitIdent(enewcls->ident_);
}

void CodeCreator::visitEVar(EVar *evar) {
    /* Code For EVar Goes Here */
    int pos = env->getPos(evar->ident_);

    i = new Push(Addr(Reg::EBP, pos).toStr());
    emit(i);
    visitIdent(evar->ident_);
}

void CodeCreator::visitELitInt(ELitInt *elitint) {
    /* Code For ELitInt Goes Here */
    stringstream ss;

    ss << "$" << elitint->integer_;
    i = new Push(ss.str());
    emit(i);

    visitInteger(elitint->integer_);
}

void CodeCreator::visitELitTrue(ELitTrue *elittrue) {
    /* Code For ELitTrue Goes Here */
    i = new Push("$1");
    emit(i);
}

void CodeCreator::visitELitFalse(ELitFalse *elitfalse) {
    /* Code For ELitFalse Goes Here */
    i = new Push("$0");
    emit(i);
}

void CodeCreator::visitEApp(EApp *eapp) {
    /* Code For EApp Goes Here */

    visitIdent(eapp->ident_);
    eapp->listexpr_->accept(this);
}

void CodeCreator::visitEString(EString *estring) {
    /* Code For EString Goes Here */

    visitString(estring->string_);
}

void CodeCreator::visitNeg(Neg *neg) {
    /* Code For Neg Goes Here */

    neg->expr_->accept(this);

    i = new Pop(Addr(Reg::ECX).toStr());
    emit(i);
    i = new NegI(Addr(Reg::ECX).toStr());
    emit(i);
    i = new Push(Addr(Reg::ECX).toStr());
    emit(i);
}

void CodeCreator::visitNot(Not *n) {
    /* Code For Not Goes Here */

    n->expr_->accept(this);

    
}

void CodeCreator::visitEMul(EMul *emul) {
    /* Code For EMul Goes Here */

    emul->expr_1->accept(this);
    emul->expr_2->accept(this);

    i = new Pop(Addr(Reg::ECX).toStr());  // Second res
    emit(i);
    i = new Pop(Addr(Reg::EAX).toStr());  // First res
    emit(i);
    emul->mulop_->accept(this);
}

void CodeCreator::visitEAdd(EAdd *eadd) {
    /* Code For EAdd Goes Here */

    eadd->expr_1->accept(this);
    eadd->expr_2->accept(this);

    i = new Pop(Addr(Reg::ECX).toStr());  // Second res
    emit(i);
    i = new Pop(Addr(Reg::EAX).toStr());  // First res
    emit(i);

    eadd->addop_->accept(this);
}

void CodeCreator::visitERel(ERel *erel) {
    /* Code For ERel Goes Here */

    erel->expr_1->accept(this);
    erel->relop_->accept(this);
    erel->expr_2->accept(this);
}

void CodeCreator::visitEAnd(EAnd *eand) {
    /* Code For EAnd Goes Here */

    eand->expr_1->accept(this);
    eand->expr_2->accept(this);
}

void CodeCreator::visitEOr(EOr *eor) {
    /* Code For EOr Goes Here */

    eor->expr_1->accept(this);
    eor->expr_2->accept(this);
}

void CodeCreator::visitPlus(Plus *plus) {
    /* Code For Plus Goes Here */
    // TODO: STRINGS
    i = new Add(Addr(Reg::ECX).toStr(), Addr(Reg::EAX).toStr());
    emit(i);
    i = new Push(Addr(Reg::EAX).toStr());
    emit(i);
}

void CodeCreator::visitMinus(Minus *minus) {
    /* Code For Minus Goes Here */
    i = new Sub(Addr(Reg::ECX).toStr(), Addr(Reg::EAX).toStr());
    emit(i);
    i = new Push(Addr(Reg::EAX).toStr());
    emit(i);
}

void CodeCreator::visitTimes(Times *times) {
    /* Code For Times Goes Here */
    i = new IMul(Addr(Reg::ECX).toStr(), Addr(Reg::EAX).toStr());
    emit(i);
    i = new Push(Addr(Reg::EAX).toStr());
    emit(i);
}

void CodeCreator::visitDiv(Div *div) {
    /* Code For Div Goes Here */
    i = new Cdq();
    emit(i);
    i = new IDiv(Addr(Reg::ECX).toStr());
    emit(i);
    i = new Push(Addr(Reg::EAX).toStr());
    emit(i);
}

void CodeCreator::visitMod(Mod *mod) {
    /* Code For Mod Goes Here */
    i = new Cdq();
    emit(i);
    i = new IDiv(Addr(Reg::ECX).toStr());
    emit(i);
    i = new Push(rtoStr(Reg::EDX));
    emit(i);
}

void CodeCreator::visitLTH(LTH *lth) {
    /* Code For LTH Goes Here */
}

void CodeCreator::visitLE(LE *le) {
    /* Code For LE Goes Here */
}

void CodeCreator::visitGTH(GTH *gth) {
    /* Code For GTH Goes Here */
}

void CodeCreator::visitGE(GE *ge) {
    /* Code For GE Goes Here */
}

void CodeCreator::visitEQU(EQU *equ) {
    /* Code For EQU Goes Here */
}

void CodeCreator::visitNE(NE *ne) {
    /* Code For NE Goes Here */
}

void CodeCreator::visitListTopDef(ListTopDef *listtopdef) {
    for (ListTopDef::iterator i = listtopdef->begin(); i != listtopdef->end();
         ++i) {
        (*i)->accept(this);
    }
}

void CodeCreator::visitListArg(ListArg *listarg) {
    for (ListArg::iterator i = listarg->begin(); i != listarg->end(); ++i) {
        (*i)->accept(this);
    }
}

void CodeCreator::visitListClsElems(ListClsElems *listclselems) {
    for (ListClsElems::iterator i = listclselems->begin();
         i != listclselems->end(); ++i) {
        (*i)->accept(this);
    }
}

void CodeCreator::visitListStmt(ListStmt *liststmt) {
    for (ListStmt::iterator i = liststmt->begin(); i != liststmt->end(); ++i) {
        (*i)->accept(this);
    }
}

void CodeCreator::visitListItem(ListItem *listitem) {
    for (ListItem::iterator i = listitem->begin(); i != listitem->end(); ++i) {
        (*i)->accept(this);
    }
}

void CodeCreator::visitListType(ListType *listtype) {
    for (ListType::iterator i = listtype->begin(); i != listtype->end(); ++i) {
        (*i)->accept(this);
    }
}

void CodeCreator::visitListExpr(ListExpr *listexpr) {
    for (ListExpr::iterator i = listexpr->begin(); i != listexpr->end(); ++i) {
        (*i)->accept(this);
    }
}

void CodeCreator::visitInteger(Integer x) {
    /* Code for Integer Goes Here */
}

void CodeCreator::visitChar(Char x) {
    /* Code for Char Goes Here */
}

void CodeCreator::visitDouble(Double x) {
    /* Code for Double Goes Here */
}

void CodeCreator::visitString(String x) {
    /* Code for String Goes Here */
}

void CodeCreator::visitIdent(Ident x) {
    /* Code for Ident Goes Here */
}
