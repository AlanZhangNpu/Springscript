#ifndef SPRINGOBJECTMANAGER_H
#define SPRINGOBJECTMANAGER_H
#include <list>
#include <vector>
#include <map>
#include <functional>

#include "SpringObject.h"
#include "SpringStandardType.h"

namespace spr {

    class SpringIDListExpression;
    class SpringParagraph;
    class SpringSymbolTable;
    class __declspec(dllexport) SpringObjectManager
    {
    public:
        SpringObjectManager();
        ~SpringObjectManager();

        SpringNilPtr        create();
        SpringBoolPtr       create(const bool &b);
        SpringIntPtr        create(const unsigned &i);
        SpringIntPtr        create(const int &i);
        SpringDoublePtr     create(const double &d);
        SpringStringPtr     create(const std::string &s);

        SpringListPtr       createEmptyList();
        SpringListPtr       create(const std::vector<SpringObjectPtr> &l);
        SpringFunctionPtr   create(SpringIDListExpression *i, SpringParagraph *b);
        SpringFunctionPtr   create(const SpringStandardFunctionType &f, const std::string &d);
        SpringStructPtr     createEmptyObject();
        SpringStructPtr     create(const std::map<std::string, SpringObjectPtr> &m);
        SpringVoidPointerPtr    create(void* p, const std::string &className);

        void push(const SpringObjectPtr & p);

        int collectGarbage(SpringSymbolTable* symbolTable);
        int collectGarbage2(const std::set<SpringObjectPtr> &usefulObjects);

        void pushReturnValue(const SpringObjectPtr &r);
        SpringObjectPtr popReturnValue();

    private:
        SpringNil sprNil;
        SpringBool sprTrue = SpringBool(true);
        SpringBool sprFalse = SpringBool(false);

        std::list<SpringObjectPtr> objHeap;
        std::vector<SpringObjectPtr> returnValueStack;

        void clear();

        void tempPrintAllObject();
        void tempPrintUsefulObject(std::vector<SpringObjectPtr> u);
    };

}

#endif // SPRINGOBJECTMANAGER_H