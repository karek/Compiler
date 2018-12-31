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
    ss << "Line " << line << ": function \"" << name  << "\" was declared before\n";
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
void BasicInfoCollector::visitExpr(Expr *t) {}            // abstract class
void BasicInfoCollector::visitAddOp(AddOp *t) {}          // abstract class
void BasicInfoCollector::visitMulOp(MulOp *t) {}          // abstract class
void BasicInfoCollector::visitRelOp(RelOp *t) {}          // abstract class

void BasicInfoCollector::collect(Visitable *v, Env *e) {
    env = e;
    v->accept(this);
    checkMain();

}


void BasicInfoCollector::checkMain() {
    if (!env->existsFunction("main")) {
        string s = "There is no function main\n";
        throw(s);
    }

}

void BasicInfoCollector::visitProg(Prog *prog) {
    /* Code For Prog Goes Here */

    prog->listtopdef_->accept(this);

    // stringstream ss;
    // ss << "Variable \""  << "\" undeclared!";
    // throw(ss.str());
}

void BasicInfoCollector::visitFnDef(FnDef *fndef) {
    /* Code For FnDef Goes Here */

    fndef->type_->accept(this);


    if (!env->existsFunction(fndef->ident_)) {
        env->addFunction(fndef->ident_); // TODO: add args and result type
    }
    else { 
        throwFunctionDeclared(fndef->ident_, fndef->line_number);
    }

    visitIdent(fndef->ident_);


    fndef->listarg_->accept(this);


    fndef->block_->accept(this);
    
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

    bstmt->block_->accept(this);
}

void BasicInfoCollector::visitDecl(Decl *decl) {
    /* Code For Decl Goes Here */

    decl->type_->accept(this);
    decl->listitem_->accept(this);
}

void BasicInfoCollector::visitAss(Ass *ass) {
    /* Code For Ass Goes Here */

    visitIdent(ass->ident_);
    ass->expr_->accept(this);
}

void BasicInfoCollector::visitIncr(Incr *incr) {
    /* Code For Incr Goes Here */

    visitIdent(incr->ident_);
}

void BasicInfoCollector::visitDecr(Decr *decr) {
    /* Code For Decr Goes Here */

    visitIdent(decr->ident_);
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

    visitIdent(noinit->ident_);
}

void BasicInfoCollector::visitInit(Init *init) {
    /* Code For Init Goes Here */

    visitIdent(init->ident_);
    init->expr_->accept(this);
}

void BasicInfoCollector::visitInt(Int *i) {
    /* Code For Int Goes Here */
}

void BasicInfoCollector::visitStr(Str *str) {
    /* Code For Str Goes Here */
}

void BasicInfoCollector::visitBool(Bool *b) {
    /* Code For Bool Goes Here */
}

void BasicInfoCollector::visitVoid(Void *v) {
    /* Code For Void Goes Here */
}

void BasicInfoCollector::visitFun(Fun *fun) {
    /* Code For Fun Goes Here */

    fun->type_->accept(this);
    fun->listtype_->accept(this);
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
    ecastnull->type_->accept(this);
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
    enewarr->typename_->accept(this);
    enewarr->expr_->accept(this);
}

void BasicInfoCollector::visitENewCls(ENewCls *enewcls) {
    /* Code For ENewCls Goes Here */
    throw("Classes " + notImplemented);
    visitIdent(enewcls->ident_);
}

void BasicInfoCollector::visitEVar(EVar *evar) {
    /* Code For EVar Goes Here */

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
