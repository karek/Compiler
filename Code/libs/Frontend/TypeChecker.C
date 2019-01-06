/*** BNFC-Generated Visitor Design Pattern TypeChecker. ***/
/* This implements the common visitor design pattern.
   Note that this method uses Visitor-traversal of lists, so
   List->accept() does NOT traverse the list. This allows different
   algorithms to use context information differently. */

#include <cassert>
#include <sstream>
#include "TypeChecker.H"
using namespace std;

void throwFunctionUndeclared(string name, int line) {
    stringstream ss;
    ss << "Line " << line << ": trying to call undeclared function \"" << name
       << "\".\n";
    throw(ss.str());
}

void throwWrongType(int line, string expected, string got, string what) {
    stringstream ss;
    ss << "Line " << line << ": wrong type of expression in " << what
       << ", expected " << expected << ", received " << got << "\n";
    throw(ss.str());
}

void throwWrongTypeLog(int line, string expected, string got) {
    stringstream ss;
    ss << "Line " << line << ": wrong type in logical expression, expected "
       << expected << " , received " << got << "\n";
    throw(ss.str());
}

void throwWrongArgNumber(string name, int line, int expected, int got) {
    stringstream ss;
    ss << "Line " << line << ": wrong number of arguments in function call \""
       << name << "\" "
       << "expected " << expected << ", received " << got << ".\n";
    throw(ss.str());
}

void throwCannotConcatenate(int line, string type1, string type2) {
    stringstream ss;
    ss << "Line " << line << ": can not concatenate (+) expressions of types "
       << type1 << " " << type2 << "\n";
    throw(ss.str());
}

void throwWrongArgType(string name, int line, int nr, string expected,
                       string got) {
    stringstream ss;
    ss << "Line " << line << ": in function \"" << name << "\" "
       << "argument number " << nr << " provided with wrong type "
       << "expected " << expected << ", received " << got << ".\n";
    throw(ss.str());
}

void throwCustomError(int line, string err) {
    stringstream ss;
    ss << "Line " << line << ": " << err << "\n";
    throw(ss.str());
}

void TypeChecker::visitProgram(Program *t) {}      // abstract class
void TypeChecker::visitTopDef(TopDef *t) {}        // abstract class
void TypeChecker::visitArg(Arg *t) {}              // abstract class
void TypeChecker::visitClsElems(ClsElems *t) {}    // abstract class
void TypeChecker::visitBlock(Block *t) {}          // abstract class
void TypeChecker::visitStmt(Stmt *t) {}            // abstract class
void TypeChecker::visitItem(Item *t) {}            // abstract class
void TypeChecker::visitBasicType(BasicType *t) {}  // abstract class
void TypeChecker::visitTypeName(TypeName *t) {}    // abstract class
void TypeChecker::visitType(Type *t) {}            // abstract class
void TypeChecker::visitLVal(LVal *t) {}            // abstract class
void TypeChecker::visitExpr(Expr *t) {}            // abstract class
void TypeChecker::visitAddOp(AddOp *t) {}          // abstract class
void TypeChecker::visitMulOp(MulOp *t) {}          // abstract class
void TypeChecker::visitRelOp(RelOp *t) {}          // abstract class

void TypeChecker::checkTypes(Visitable *v, Env *e) {
    env = e;
    assert(!env->hasAnyScope());
    v->accept(this);
}

void TypeChecker::visitProg(Prog *prog) {
    /* Code For Prog Goes Here */

    prog->listtopdef_->accept(this);
}

void TypeChecker::visitFnDef(FnDef *fndef) {
    /* Code For FnDef Goes Here */

    fndef->type_->accept(this);
    curFunType = lastType;
    visitIdent(fndef->ident_);
    fndef->listarg_->accept(this);

    vector<pair<string, TType>> fargs = env->getArgs(fndef->ident_);
    env->beginBlock();  // Arguments vars
    for (int i = 0; i < fargs.size(); i++) {
        env->addVarToCurScope(fargs[i].first, fargs[i].second);
    }
    fndef->block_->accept(this);
    env->endBlock();
}

void TypeChecker::visitClsDef(ClsDef *clsdef) {
    /* Code For ClsDef Goes Here */

    visitIdent(clsdef->ident_);
    clsdef->listclselems_->accept(this);
}

void TypeChecker::visitExtClsDef(ExtClsDef *extclsdef) {
    /* Code For ExtClsDef Goes Here */

    visitIdent(extclsdef->ident_1);
    visitIdent(extclsdef->ident_2);
    extclsdef->listclselems_->accept(this);
}

void TypeChecker::visitAr(Ar *ar) {
    /* Code For Ar Goes Here */

    ar->type_->accept(this);
    visitIdent(ar->ident_);
}

void TypeChecker::visitClsMethod(ClsMethod *clsmethod) {
    /* Code For ClsMethod Goes Here */

    clsmethod->type_->accept(this);
    visitIdent(clsmethod->ident_);
    clsmethod->listarg_->accept(this);
    clsmethod->block_->accept(this);
}

void TypeChecker::visitClsField(ClsField *clsfield) {
    /* Code For ClsField Goes Here */

    clsfield->type_->accept(this);
    visitIdent(clsfield->ident_);
}

void TypeChecker::visitBlk(Blk *blk) {
    /* Code For Blk Goes Here */
    env->beginBlock();
    blk->liststmt_->accept(this);
    env->endBlock();
}

void TypeChecker::visitEmpty(Empty *empty) {
    /* Code For Empty Goes Here */
}

void TypeChecker::visitBStmt(BStmt *bstmt) {
    /* Code For BStmt Goes Here */

    bstmt->block_->accept(this);
}

void TypeChecker::visitDecl(Decl *decl) {
    /* Code For Decl Goes Here */

    decl->type_->accept(this);
    decl->listitem_->accept(this);
}

void TypeChecker::visitAss(Ass *ass) {
    /* Code For Ass Goes Here */

    // l type = right type
    ass->lval_->accept(this);
    TType lvalT = lastType;
    ass->expr_->accept(this);

    if (!(lvalT == lastType)) {
        throwWrongType(ass->line_number, lvalT.toStr(), lastType.toStr(),
                       "assignment");
    }
}

void TypeChecker::visitIncr(Incr *incr) {
    /* Code For Incr Goes Here */
    // int
    incr->lval_->accept(this);
    TType expected = TType(vType::tInt);
    if (!(expected == lastType)) {
        throwWrongType(incr->line_number, expected.toStr(), lastType.toStr(),
                       "increment");
    }
}

void TypeChecker::visitDecr(Decr *decr) {
    /* Code For Decr Goes Here */
    // int only
    decr->lval_->accept(this);

    TType expected = TType(vType::tInt);
    if (!(expected == lastType)) {
        throwWrongType(decr->line_number, expected.toStr(), lastType.toStr(),
                       "decrement");
    }
}

void TypeChecker::visitRet(Ret *ret) {
    /* Code For Ret Goes Here */

    ret->expr_->accept(this);
    if (!(curFunType == lastType)) {
        throwWrongType(ret->line_number, curFunType.toStr(), lastType.toStr(),
                       "return");
    }
}

void TypeChecker::visitVRet(VRet *vret) {
    /* Code For VRet Goes Here */
    if (!curFunType.isVoid()) {
        throwCustomError(
            vret->line_number,
            "function trying to return void, while its type is different");
    }
}

void TypeChecker::visitCond(Cond *cond) {
    /* Code For Cond Goes Here */

    cond->expr_->accept(this);
    TType expected = TType(vType::tBool);
    if (!(expected == lastType)) {
        throwWrongType(cond->line_number, expected.toStr(), lastType.toStr(),
                       "if");
    }

    cond->stmt_->accept(this);
}

void TypeChecker::visitCondElse(CondElse *condelse) {
    /* Code For CondElse Goes Here */

    condelse->expr_->accept(this);

    TType expected = TType(vType::tBool);
    if (!(expected == lastType)) {
        throwWrongType(condelse->line_number, expected.toStr(),
                       lastType.toStr(), "if else");
    }

    condelse->stmt_1->accept(this);
    condelse->stmt_2->accept(this);
}

void TypeChecker::visitWhile(While *w) {
    /* Code For While Goes Here */

    w->expr_->accept(this);
    TType expected = TType(vType::tBool);
    if (!(expected == lastType)) {
        throwWrongType(w->line_number, expected.toStr(), lastType.toStr(),
                       "while");
    }
    w->stmt_->accept(this);
}

void TypeChecker::visitFor(For *f) {
    /* Code For For Goes Here */

    f->type_->accept(this);
    visitIdent(f->ident_1);
    visitIdent(f->ident_2);
    f->stmt_->accept(this);
}

void TypeChecker::visitSExp(SExp *sexp) {
    /* Code For SExp Goes Here */

    sexp->expr_->accept(this);
}

void TypeChecker::visitNoInit(NoInit *noinit) {
    /* Code For NoInit Goes Here */
    env->addVarToCurScope(noinit->ident_, lastType);
    visitIdent(noinit->ident_);
}

void TypeChecker::visitInit(Init *init) {
    /* Code For Init Goes Here */

    env->addVarToCurScope(init->ident_, lastType);

    TType declType = lastType; 
    visitIdent(init->ident_);

    init->expr_->accept(this);

    if(!(declType == lastType)) {
        throwWrongType(init->line_number, declType.toStr(), lastType.toStr(), "declaration");
    }

}

void TypeChecker::visitInt(Int *i) {
    /* Code For Int Goes Here */
    lastType = TType(vType::tInt);
}

void TypeChecker::visitStr(Str *str) {
    /* Code For Str Goes Here */
    lastType = TType(vType::tStr);
}

void TypeChecker::visitBool(Bool *b) {
    /* Code For Bool Goes Here */
    lastType = TType(vType::tBool);
}

void TypeChecker::visitVoid(Void *v) {
    /* Code For Void Goes Here */
    lastType = TType(vType::tVoid);
}

void TypeChecker::visitFun(Fun *fun) {
    /* Code For Fun Goes Here */

    fun->type_->accept(this);
    fun->listtype_->accept(this);
}

void TypeChecker::visitBType(BType *btype) {
    /* Code For BType Goes Here */

    btype->basictype_->accept(this);
}

void TypeChecker::visitClsType(ClsType *clstype) {
    /* Code For ClsType Goes Here */

    visitIdent(clstype->ident_);
}

void TypeChecker::visitArrayType(ArrayType *arraytype) {
    /* Code For ArrayType Goes Here */

    arraytype->typename_->accept(this);
}

void TypeChecker::visitNormalType(NormalType *normaltype) {
    /* Code For NormalType Goes Here */

    normaltype->typename_->accept(this);
}

void TypeChecker::visitLvVar(LvVar *lvvar) {
    /* Code For LvVar Goes Here */

    TType t = env->lookupVarType(lvvar->ident_);
    assert(t.isAnything());
    lastType = t;
    visitIdent(lvvar->ident_);
}

void TypeChecker::visitLvTab(LvTab *lvtab) {
    /* Code For LvTab Goes Here */

    lvtab->expr_1->accept(this);
    lvtab->expr_2->accept(this);
}

void TypeChecker::visitLvAttr(LvAttr *lvattr) {
    /* Code For LvAttr Goes Here */

    lvattr->expr_->accept(this);
    visitIdent(lvattr->ident_);
}

void TypeChecker::visitEAttr(EAttr *eattr) {
    /* Code For EAttr Goes Here */

    eattr->expr_->accept(this);
    visitIdent(eattr->ident_);
}

void TypeChecker::visitEMetCall(EMetCall *emetcall) {
    /* Code For EMetCall Goes Here */

    emetcall->expr_->accept(this);
    visitIdent(emetcall->ident_);
    emetcall->listexpr_->accept(this);
}

void TypeChecker::visitECastNull(ECastNull *ecastnull) {
    /* Code For ECastNull Goes Here */

    visitIdent(ecastnull->ident_);
}

void TypeChecker::visitEAt(EAt *eat) {
    /* Code For EAt Goes Here */

    eat->expr_1->accept(this);
    eat->expr_2->accept(this);
}

void TypeChecker::visitENewArr(ENewArr *enewarr) {
    /* Code For ENewArr Goes Here */

    enewarr->basictype_->accept(this);
    enewarr->expr_->accept(this);
}

void TypeChecker::visitENewClArr(ENewClArr *enewclarr) {
    /* Code For ENewClArr Goes Here */

    visitIdent(enewclarr->ident_);
    enewclarr->expr_->accept(this);
}

void TypeChecker::visitENewCls(ENewCls *enewcls) {
    /* Code For ENewCls Goes Here */

    visitIdent(enewcls->ident_);
}

void TypeChecker::visitEVar(EVar *evar) {
    /* Code For EVar Goes Here */
    // Set Type
    TType t = env->lookupVarType(evar->ident_);
    assert(t.isAnything());
    lastType = t;
    visitIdent(evar->ident_);
}

void TypeChecker::visitELitInt(ELitInt *elitint) {
    /* Code For ELitInt Goes Here */
    lastType = TType(vType::tInt);
    visitInteger(elitint->integer_);
}

void TypeChecker::visitELitTrue(ELitTrue *elittrue) {
    /* Code For ELitTrue Goes Here */
    lastType = TType(vType::tBool);
}

void TypeChecker::visitELitFalse(ELitFalse *elitfalse) {
    /* Code For ELitFalse Goes Here */
    lastType = TType(vType::tBool);
}

void TypeChecker::visitEApp(EApp *eapp) {
    /* Code For EApp Goes Here */
    if (!env->existsFunction(eapp->ident_))
        throwFunctionUndeclared(eapp->ident_, eapp->line_number);

    if (eapp->listexpr_->size() != env->getArgsNum(eapp->ident_))
        throwWrongArgNumber(eapp->ident_, eapp->line_number,
                            env->getArgsNum(eapp->ident_),
                            eapp->listexpr_->size());

    // Check argument types
    visitIdent(eapp->ident_);

    vector<pair<string, TType>> fargs = env->getArgs(eapp->ident_);
    vector<TType> appTypes;

    for (ListExpr::iterator i = eapp->listexpr_->begin(); i != eapp->listexpr_->end(); ++i) {
        (*i)->accept(this);
        appTypes.push_back(lastType);
    }

    for (int i = 0; i < fargs.size(); i++) {
        if (!(appTypes[i] == fargs[i].second))
            throwWrongArgType(eapp->ident_, eapp->line_number, i+1,
                              fargs[i].second.toStr(), appTypes[i].toStr());
    }

    eapp->listexpr_->accept(this);

    lastType = env->getRetType(eapp->ident_);
}

void TypeChecker::visitEString(EString *estring) {
    /* Code For EString Goes Here */
    lastType = TType(vType::tStr);
    visitString(estring->string_);
}

void TypeChecker::visitNeg(Neg *neg) {
    /* Code For Neg Goes Here */

    neg->expr_->accept(this);
    if (!lastType.isInt())
        throwWrongType(neg->line_number, TType(vType::tInt).toStr(),
                       lastType.toStr(), "Negation");
}

void TypeChecker::visitNot(Not *n) {
    /* Code For Not Goes Here */

    n->expr_->accept(this);
    if (!lastType.isBool())
        throwWrongType(n->line_number, TType(vType::tBool).toStr(),
                       lastType.toStr(), "Not");
}

void TypeChecker::visitEMul(EMul *emul) {
    /* Code For EMul Goes Here */

    emul->expr_1->accept(this);
    TType first = lastType;
    emul->mulop_->accept(this);
    emul->expr_2->accept(this);
    if (!first.isInt())
        throwWrongType(emul->line_number, TType(vType::tInt).toStr(),
                       first.toStr(), "Mul/Div/Mod");

    if (!lastType.isInt())
        throwWrongType(emul->line_number, TType(vType::tInt).toStr(),
                       first.toStr(), "Mul/Div/Mod");
}

void TypeChecker::visitEAdd(EAdd *eadd) {
    /* Code For EAdd Goes Here */

    eadd->expr_1->accept(this);
    TType first = lastType;
    eadd->addop_->accept(this);
    TOp op = lastOp;
    eadd->expr_2->accept(this);

    if (op.isPlus()) {
        if (first.isString() || lastType.isString()) {
            if (!first.isString() || !lastType.isString())
                throwCannotConcatenate(eadd->line_number, first.toStr(),
                                       lastType.toStr());
            return;
        }
    }

    if (!first.isInt())
        throwWrongType(eadd->line_number, TType(vType::tInt).toStr(),
                       first.toStr(), "Add/Sub");

    if (!lastType.isInt())
        throwWrongType(eadd->line_number, TType(vType::tInt).toStr(),
                       first.toStr(), "Add/Sub");
}

void TypeChecker::visitERel(ERel *erel) {
    /* Code For ERel Goes Here */

    erel->expr_1->accept(this);
    TType first = lastType;
    erel->relop_->accept(this);
    erel->expr_2->accept(this);

    if (!(lastRelop.isEq() || lastRelop.isNeq())) {
        // All other ops work only for ints
        if (!first.isInt())
            throwWrongType(erel->line_number, TType(vType::tInt).toStr(),
                           first.toStr(), "Relation");

        if (!lastType.isInt())
            throwWrongType(erel->line_number, TType(vType::tInt).toStr(),
                           first.toStr(), "Relation");
    } else {
        // Eq or neq
        if (!(first == lastType)) {
            throwCustomError(
                erel->line_number,
                "Both types should be the same in eq/neq relation.");
        }
    }

    lastType = TType(vType::tBool);
}

void TypeChecker::visitEAnd(EAnd *eand) {
    /* Code For EAnd Goes Here */

    eand->expr_1->accept(this);
    TType first = lastType;
    eand->expr_2->accept(this);
    if (!first.isBool())
        throwWrongTypeLog(eand->line_number, TType(vType::tBool).toStr(),
                          first.toStr());

    if (!lastType.isBool())
        throwWrongTypeLog(eand->line_number, TType(vType::tBool).toStr(),
                          lastType.toStr());
}

void TypeChecker::visitEOr(EOr *eor) {
    /* Code For EOr Goes Here */

    eor->expr_1->accept(this);
    TType first = lastType;
    eor->expr_2->accept(this);

    if (!first.isBool())
        throwWrongTypeLog(eor->line_number, TType(vType::tBool).toStr(),
                          first.toStr());

    if (!lastType.isBool())
        throwWrongTypeLog(eor->line_number, TType(vType::tBool).toStr(),
                          lastType.toStr());
}

void TypeChecker::visitPlus(Plus *plus) {
    /* Code For Plus Goes Here */
    lastOp = TOp(vOp::oPlus);
}

void TypeChecker::visitMinus(Minus *minus) {
    /* Code For Minus Goes Here */
    lastOp = TOp(vOp::oMinus);
}

void TypeChecker::visitTimes(Times *times) {
    /* Code For Times Goes Here */
    lastOp = TOp(vOp::oMul);
}

void TypeChecker::visitDiv(Div *div) {
    /* Code For Div Goes Here */
    lastOp = TOp(vOp::oDiv);
}

void TypeChecker::visitMod(Mod *mod) {
    /* Code For Mod Goes Here */
    lastOp = TOp(vOp::oMod);
}

void TypeChecker::visitLTH(LTH *lth) {
    /* Code For LTH Goes Here */
    lastRelop = TRelop(vRelop::oLt);
}

void TypeChecker::visitLE(LE *le) {
    /* Code For LE Goes Here */
    lastRelop = TRelop(vRelop::oLe);
}

void TypeChecker::visitGTH(GTH *gth) {
    /* Code For GTH Goes Here */
    lastRelop = TRelop(vRelop::oGt);
}

void TypeChecker::visitGE(GE *ge) {
    /* Code For GE Goes Here */
    lastRelop = TRelop(vRelop::oGe);
}

void TypeChecker::visitEQU(EQU *equ) {
    /* Code For EQU Goes Here */
    lastRelop = TRelop(vRelop::oEq);
}

void TypeChecker::visitNE(NE *ne) {
    /* Code For NE Goes Here */
    lastRelop = TRelop(vRelop::oNeq);
}

void TypeChecker::visitListTopDef(ListTopDef *listtopdef) {
    for (ListTopDef::iterator i = listtopdef->begin(); i != listtopdef->end();
         ++i) {
        (*i)->accept(this);
    }
}

void TypeChecker::visitListArg(ListArg *listarg) {
    for (ListArg::iterator i = listarg->begin(); i != listarg->end(); ++i) {
        (*i)->accept(this);
    }
}

void TypeChecker::visitListClsElems(ListClsElems *listclselems) {
    for (ListClsElems::iterator i = listclselems->begin();
         i != listclselems->end(); ++i) {
        (*i)->accept(this);
    }
}

void TypeChecker::visitListStmt(ListStmt *liststmt) {
    for (ListStmt::iterator i = liststmt->begin(); i != liststmt->end(); ++i) {
        (*i)->accept(this);
    }
}

void TypeChecker::visitListItem(ListItem *listitem) {
    for (ListItem::iterator i = listitem->begin(); i != listitem->end(); ++i) {
        (*i)->accept(this);
    }
}

void TypeChecker::visitListType(ListType *listtype) {
    for (ListType::iterator i = listtype->begin(); i != listtype->end(); ++i) {
        (*i)->accept(this);
    }
}

void TypeChecker::visitListExpr(ListExpr *listexpr) {
    for (ListExpr::iterator i = listexpr->begin(); i != listexpr->end(); ++i) {
        (*i)->accept(this);
    }
}

void TypeChecker::visitInteger(Integer x) {
    /* Code for Integer Goes Here */
}

void TypeChecker::visitChar(Char x) {
    /* Code for Char Goes Here */
}

void TypeChecker::visitDouble(Double x) {
    /* Code for Double Goes Here */
}

void TypeChecker::visitString(String x) {
    /* Code for String Goes Here */
}

void TypeChecker::visitIdent(Ident x) {
    /* Code for Ident Goes Here */
}
