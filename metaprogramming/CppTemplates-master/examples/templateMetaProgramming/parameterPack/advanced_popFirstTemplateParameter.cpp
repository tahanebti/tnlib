
#include "util.hpp"

template <int firstParam>
int popFirstTemplateParameter() {
    return firstParam;
}

template <int firstParam, int... otherParams>
void popFirstTemplateParameter()
    { printParameters<otherParams...>(); }

int main()
{
    popFirstTemplateParameter<1,2,3,4,5>();
}
