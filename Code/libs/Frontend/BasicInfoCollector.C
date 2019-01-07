/*** BNFC-Generated Visitor Design Pattern Skeleton. ***/
/* This implements the common visitor design pattern.
   Note that this method uses Visitor-traversal of lists, so
   List->accept() does NOT traverse the list. This allows different
   algorithms to use context information differently. */

#include <sstream>
#include "BasicInfoCollector.H"

using namespace std;

void throwFunctionDeclared(string name, int line) {
    stringstream ss;
    ss << "Line " << line << ": function \"" << name
       << "\" was declared before.\n";
    throw(ss.str());
}

void throwVariableDeclared(string name, int line, TType t) {
    stringstream ss;
    ss << "Line " << line << ": variable \"" << name << "\" of type "
       << t.toStr() << " was declared before.\n";
    throw(ss.str());
}

void throwVoidVar(string name, int line) {
    stringstream ss;
    ss << "Line " << line << ": variable \"" << name
       << "\" can not be of type void. \n";
    throw(ss.str());
}

void throwUseofUndeclaredVar(string name, int line) {
    stringstream ss;
    ss << "Line " << line << ": variable \"" << name
       << "\" was not declared before use.\n";
    throw(ss.str());
}

void throwSameNameArgs(int line, string name, string var) {
    stringstream ss;
    ss << "Line " << line << ": argument name \"" << var << "\" repeated in function \"" << name
       << "\".\n";
    throw(ss.str());
}


void BasicInfoCollector::visitProgram(Program *t) {}      // abstract class
void BasicInfoCollector::visitTopDef(TopDef *t) {}        // abstract class
void BasicInfoCollector::visitArg(Arg *t) {}              // abstract class
void BasicInfoCollector::visitClsElems(ClsElems *t) {}    // abstract class
void BasicInfoCollector::visitBlock(Block *t) {}          // abstract class
void BasicInfoCollector::visitStmt(Stmt *t) {}            // abstract class
void BasicInfoCollector::visitItem(Item *t) {}            // abstract class
void BasicInfoCollector::visitBasicType(BasicType *t) {}  // abstract class
void BasicInfoCollector::visitTypeName(TypeName *t) {}    // abstract class
void BasicInfoCollector::visitType(Type *t) {}            // abstract class
void BasicInfoCollector::visitLVal(LVal *t) {}            // abstract class
void BasicInfoCollector::visitExpr(Expr *t) {}            // abstract class
void BasicInfoCollector::visitAddOp(AddOp *t) {}          // abstract class
void BasicInfoCollector::visitMulOp(MulOp *t) {}          // abstract class
void BasicInfoCollector::visitRelOp(RelOp *t) {}          // abstract class

void BasicInfoCollector::collect(Visitable *v, Env *e) {
    env = e;
    v->accept(this);
    checkMain();
    addPreimplementedFunctions();
}

void BasicInfoCollector::addPreimplementedFunctions() {
    vector<pair<string, TType> > args;

    args.push_back({"x", TType(vType::tInt)});
    env->addFunction("printInt", TType(vType::tVoid), args); 

    args.clear();
    args.push_back({"s", TType(vType::tStr)});
    env->addFunction("printString", TType(vType::tVoid), args); 

    args.clear();
    env->addFunction("error", TType(vType::tVoid), args); 
    env->addFunction("readInt", TType(vType::tInt), args); 
    env->addFunction("readString", TType(vType::tStr), args); 
}

void BasicInfoCollector::checkMain() {
    if (!env->existsFunction("main")) {
        string s = "There is no function main.\n";
        throw(s);
    }

    if (!env->getRetType("main").isInt()) {
        string s = "Function main should return int type.\n";
        throw(s);
    }

    if (env->getArgs("main").size() > 0) {
        string s = "Function main should not take any arguments.\n";
        throw(s);
    }
}

void BasicInfoCollector::visitProg(Prog *prog) {
    /* Code For Prog Goes Here */

    prog->listtopdef_->accept(this);
}

void BasicInfoCollector::visitFnDef(FnDef *fndef) {
    /* Code For FnDef Goes Here */

    fndef->type_->accept(this);
    TType retT = lastType;

    curFun = fndef->ident_;
    visitIdent(fndef->ident_);

    fargs.clear();
    fndef->listarg_->accept(this);

    if (!env->existsFunction(fndef->ident_)) {
        env->addFunction(fndef->ident_, retT, fargs);
    } else {
        throwFunctionDeclared(fndef->ident_, fndef->line_number);
    }

    env->beginBlock();  // Arguments vars
    for (int i = 0; i < fargs.size(); i++) {
        if(env->isDeclaredInCurScope(fargs[i].first)) 
            throwSameNameArgs(fndef->line_number, fndef->ident_, fargs[i].first);
        env->addVarToCurScope(fargs[i].first, fargs[i].second);
    }
    fndef->block_->accept(this);
    env->endBlock();
}

void BasicInfoCollector::visitClsDef(ClsDef *clsdef) {
    /* Code For ClsDef Goes Here */

    throw("Classes " + notImplemented);
    visitIdent(clsdef->ident_);
    clsdef->listclselems_->accept(this);
}

void BasicInfoCollector::visitExtClsDef(ExtClsDef *extclsdef) {
    /* Code For ExtClsDef Goes Here */
    throw("Classes " + notImplemented);
    visitIdent(extclsdef->ident_1);
    visitIdent(extclsdef->ident_2);
    extclsdef->listclselems_->accept(this);
}

void BasicInfoCollector::visitAr(Ar *ar) {
    /* Code For Ar Goes Here */

    ar->type_->accept(this);
    fargs.push_back({ar->ident_, lastType});
    visitIdent(ar->ident_);
}

void BasicInfoCollector::visitClsMethod(ClsMethod *clsmethod) {
    /* Code For ClsMethod Goes Here */
    throw("Classes " + notImplemented);
    clsmethod->type_->accept(this);
    visitIdent(clsmethod->ident_);
    clsmethod->listarg_->accept(this);
    clsmethod->block_->accept(this);
}

void BasicInfoCollector::visitClsField(ClsField *clsfield) {
    /* Code For ClsField Goes Here */
    throw("Classes " + notImplemented);
    clsfield->type_->accept(this);
    visitIdent(clsfield->ident_);
}

void BasicInfoCollector::visitBlk(Blk *blk) {
    /* Code For Blk Goes Here */
    
    blk->liststmt_->accept(this);
    
}

void BasicInfoCollector::visitEmpty(Empty *empty) {
    /* Code For Empty Goes Here */
}

void BasicInfoCollector::visitBStmt(BStmt *bstmt) {
    /* Code For BStmt Goes Here */
    env->beginBlock();
    bstmt->block_->accept(this);
    env->endBlock();
}

void BasicInfoCollector::visitDecl(Decl *decl) {
    /* Code For Decl Goes Here */

    decl->type_->accept(this);

    env->addLocalsCnt(curFun, decl->listitem_->size());

    decl->listitem_->accept(this);
}

void BasicInfoCollector::visitAss(Ass *ass) {
    /* Code For Ass Goes Here */

    ass->lval_->accept(this);
    ass->expr_->accept(this);
}

void BasicInfoCollector::visitIncr(Incr *incr) {
    /* Code For Incr Goes Here */

    incr->lval_->accept(this);
}

void BasicInfoCollector::visitDecr(Decr *decr) {
    /* Code For Decr Goes Here */

    decr->lval_->accept(this);
}

void BasicInfoCollector::visitRet(Ret *ret) {
    /* Code For Ret Goes Here */

    ret->expr_->accept(this);
}

void BasicInfoCollector::visitVRet(VRet *vret) {
    /* Code For VRet Goes Here */
}

void BasicInfoCollector::visitCond(Cond *cond) {
    /* Code For Cond Goes Here */

    cond->expr_->accept(this);
    cond->stmt_->accept(this);
}

void BasicInfoCollector::visitCondElse(CondElse *condelse) {
    /* Code For CondElse Goes Here */

    condelse->expr_->accept(this);
    condelse->stmt_1->accept(this);
    condelse->stmt_2->accept(this);
}

void BasicInfoCollector::visitWhile(While *w) {
    /* Code For While Goes Here */

    w->expr_->accept(this);
    w->stmt_->accept(this);
}

void BasicInfoCollector::visitFor(For *f) {
    /* Code For For Goes Here */
    throw("For " + notImplemented);
    f->type_->accept(this);
    visitIdent(f->ident_1);
    visitIdent(f->ident_2);
    f->stmt_->accept(this);
}

void BasicInfoCollector::visitSExp(SExp *sexp) {
    /* Code For SExp Goes Here */

    sexp->expr_->accept(this);
}

void BasicInfoCollector::visitNoInit(NoInit *noinit) {
    /* Code For NoInit Goes Here */

    if (lastType.isVoid())
        throwVoidVar(noinit->ident_, noinit->line_number);

    if (env->isDeclaredInCurScope(noinit->ident_)) {
        throwVariableDeclared(noinit->ident_, noinit->line_number, lastType);
    } else {
        env->addVarToCurScope(noinit->ident_, lastType);
    }
    visitIdent(noinit->ident_);
}

void BasicInfoCollector::visitInit(Init *init) {
    /* Code For Init Goes Here */

    if (lastType.isVoid())
        throwVoidVar(init->ident_, init->line_number);

    if (env->isDeclaredInCurScope(init->ident_)) {
        throwVariableDeclared(init->ident_, init->line_number, lastType);
    } else {
        env->addVarToCurScope(init->ident_, lastType);
    }

    visitIdent(init->ident_);
    init->expr_->accept(this);
}

void BasicInfoCollector::visitInt(Int *i) {
    /* Code For Int Goes Here */
    lastType = TType(vType::tInt);
}

void BasicInfoCollector::visitStr(Str *str) {
    /* Code For Str Goes Here */
    lastType = TType(vType::tStr);
}

void BasicInfoCollector::visitBool(Bool *b) {
    /* Code For Bool Goes Here */
    lastType = TType(vType::tBool);
}

void BasicInfoCollector::visitVoid(Void *v) {
    /* Code For Void Goes Here */
    lastType = TType(vType::tVoid);
}

void BasicInfoCollector::visitFun(Fun *fun) {
    /* Code For Fun Goes Here */

    // fun->type_->accept(this);
    // fun->listtype_->accept(this);
}

void BasicInfoCollector::visitBType(BType *btype) {
    /* Code For BType Goes Here */

    btype->basictype_->accept(this);
}

void BasicInfoCollector::visitClsType(ClsType *clstype) {
    /* Code For ClsType Goes Here */
    throw("Classes " + notImplemented);
    visitIdent(clstype->ident_);
}

void BasicInfoCollector::visitArrayType(ArrayType *arraytype) {
    /* Code For ArrayType Goes Here */
    throw("Arrays " + notImplemented);
    arraytype->typename_->accept(this);
}

void BasicInfoCollector::visitNormalType(NormalType *normaltype) {
    /* Code For NormalType Goes Here */

    normaltype->typename_->accept(this);
}

void BasicInfoCollector::visitLvVar(LvVar *lvvar) {
    /* Code For LvVar Goes Here */
    if (!env->lookupVar(lvvar->ident_))
        throwUseofUndeclaredVar(lvvar->ident_, lvvar->line_number);
    visitIdent(lvvar->ident_);
}

void BasicInfoCollector::visitLvTab(LvTab *lvtab) {
    /* Code For LvTab Goes Here */
    throw("Arrays " + notImplemented);
    lvtab->expr_1->accept(this);
    lvtab->expr_2->accept(this);
}

void BasicInfoCollector::visitLvAttr(LvAttr *lvattr) {
    /* Code For LvAttr Goes Here */
    throw("Classes " + notImplemented);
    lvattr->expr_->accept(this);
    visitIdent(lvattr->ident_);
}

void BasicInfoCollector::visitEAttr(EAttr *eattr) {
    /* Code For EAttr Goes Here */
    throw("Classes " + notImplemented);
    eattr->expr_->accept(this);
    visitIdent(eattr->ident_);
}

void BasicInfoCollector::visitEMetCall(EMetCall *emetcall) {
    /* Code For EMetCall Goes Here */
    throw("Classes " + notImplemented);
    emetcall->expr_->accept(this);
    visitIdent(emetcall->ident_);
    emetcall->listexpr_->accept(this);
}

void BasicInfoCollector::visitECastNull(ECastNull *ecastnull) {
    /* Code For ECastNull Goes Here */
    throw("Classes " + notImplemented);
    visitIdent(ecastnull->ident_);
}

void BasicInfoCollector::visitEAt(EAt *eat) {
    /* Code For EAt Goes Here */
    throw("Arrays " + notImplemented);
    eat->expr_1->accept(this);
    eat->expr_2->accept(this);
}

void BasicInfoCollector::visitENewArr(ENewArr *enewarr) {
    /* Code For ENewArr Goes Here */
    throw("Arrays " + notImplemented);
    enewarr->basictype_->accept(this);
    enewarr->expr_->accept(this);
}

void BasicInfoCollector::visitENewClArr(ENewClArr *enewclarr) {
    /* Code For ENewClArr Goes Here */
    throw("Arrays " + notImplemented);
    visitIdent(enewclarr->ident_);
    enewclarr->expr_->accept(this);
}

void BasicInfoCollector::visitENewCls(ENewCls *enewcls) {
    /* Code For ENewCls Goes Here */
    throw("Classes " + notImplemented);
    visitIdent(enewcls->ident_);
}

void BasicInfoCollector::visitEVar(EVar *evar) {
    /* Code For EVar Goes Here */
    if (!env->lookupVar(evar->ident_))
        throwUseofUndeclaredVar(evar->ident_, evar->line_number);
    visitIdent(evar->ident_);
}

void BasicInfoCollector::visitELitInt(ELitInt *elitint) {
    /* Code For ELitInt Goes Here */

    visitInteger(elitint->integer_);
}

void BasicInfoCollector::visitELitTrue(ELitTrue *elittrue) {
    /* Code For ELitTrue Goes Here */
}

void BasicInfoCollector::visitELitFalse(ELitFalse *elitfalse) {
    /* Code For ELitFalse Goes Here */
}

void BasicInfoCollector::visitEApp(EApp *eapp) {
    /* Code For EApp Goes Here */

    visitIdent(eapp->ident_);
    eapp->listexpr_->accept(this);

}

void BasicInfoCollector::visitEString(EString *estring) {
    /* Code For EString Goes Here */

    visitString(estring->string_);
}

void BasicInfoCollector::visitNeg(Neg *neg) {
    /* Code For Neg Goes Here */

    neg->expr_->accept(this);
}

void BasicInfoCollector::visitNot(Not *n) {
    /* Code For Not Goes Here */

    n->expr_->accept(this);
}

void BasicInfoCollector::visitEMul(EMul *emul) {
    /* Code For EMul Goes Here */

    emul->expr_1->accept(this);
    emul->mulop_->accept(this);
    emul->expr_2->accept(this);
}

void BasicInfoCollector::visitEAdd(EAdd *eadd) {
    /* Code For EAdd Goes Here */

    eadd->expr_1->accept(this);
    eadd->addop_->accept(this);
    eadd->expr_2->accept(this);
}

void BasicInfoCollector::visitERel(ERel *erel) {
    /* Code For ERel Goes Here */

    erel->expr_1->accept(this);
    erel->relop_->accept(this);
    erel->expr_2->accept(this);
}

void BasicInfoCollector::visitEAnd(EAnd *eand) {
    /* Code For EAnd Goes Here */

    eand->expr_1->accept(this);
    eand->expr_2->accept(this);
}

void BasicInfoCollector::visitEOr(EOr *eor) {
    /* Code For EOr Goes Here */

    eor->expr_1->accept(this);
    eor->expr_2->accept(this);
}

void BasicInfoCollector::visitPlus(Plus *plus) {
    /* Code For Plus Goes Here */
}

void BasicInfoCollector::visitMinus(Minus *minus) {
    /* Code For Minus Goes Here */
}

void BasicInfoCollector::visitTimes(Times *times) {
    /* Code For Times Goes Here */
}

void BasicInfoCollector::visitDiv(Div *div) {
    /* Code For Div Goes Here */
}

void BasicInfoCollector::visitMod(Mod *mod) {
    /* Code For Mod Goes Here */
}

void BasicInfoCollector::visitLTH(LTH *lth) {
    /* Code For LTH Goes Here */
}

void BasicInfoCollector::visitLE(LE *le) {
    /* Code For LE Goes Here */
}

void BasicInfoCollector::visitGTH(GTH *gth) {
    /* Code For GTH Goes Here */
}

void BasicInfoCollector::visitGE(GE *ge) {
    /* Code For GE Goes Here */
}

void BasicInfoCollector::visitEQU(EQU *equ) {
    /* Code For EQU Goes Here */
}

void BasicInfoCollector::visitNE(NE *ne) {
    /* Code For NE Goes Here */
}

void BasicInfoCollector::visitListTopDef(ListTopDef *listtopdef) {
    for (ListTopDef::iterator i = listtopdef->begin(); i != listtopdef->end();
         ++i) {
        (*i)->accept(this);
    }
}

void BasicInfoCollector::visitListArg(ListArg *listarg) {
    for (ListArg::iterator i = listarg->begin(); i != listarg->end(); ++i) {
        (*i)->accept(this);
    }
}

void BasicInfoCollector::visitListClsElems(ListClsElems *listclselems) {
    for (ListClsElems::iterator i = listclselems->begin();
         i != listclselems->end(); ++i) {
        (*i)->accept(this);
    }
}

void BasicInfoCollector::visitListStmt(ListStmt *liststmt) {
    for (ListStmt::iterator i = liststmt->begin(); i != liststmt->end(); ++i) {
        (*i)->accept(this);
    }
}

void BasicInfoCollector::visitListItem(ListItem *listitem) {
    for (ListItem::iterator i = listitem->begin(); i != listitem->end(); ++i) {
        (*i)->accept(this);
    }
}

void BasicInfoCollector::visitListType(ListType *listtype) {
    for (ListType::iterator i = listtype->begin(); i != listtype->end(); ++i) {
        (*i)->accept(this);
    }
}

void BasicInfoCollector::visitListExpr(ListExpr *listexpr) {
    for (ListExpr::iterator i = listexpr->begin(); i != listexpr->end(); ++i) {
        (*i)->accept(this);
    }
}

void BasicInfoCollector::visitInteger(Integer x) {
    /* Code for Integer Goes Here */
}

void BasicInfoCollector::visitChar(Char x) {
    /* Code for Char Goes Here */
}

void BasicInfoCollector::visitDouble(Double x) {
    /* Code for Double Goes Here */
}

void BasicInfoCollector::visitString(String x) {
    /* Code for String Goes Here */
}

void BasicInfoCollector::visitIdent(Ident x) {
    /* Code for Ident Goes Here */
}
