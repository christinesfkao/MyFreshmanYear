#include <cstdio>
#include <ctime>

int reverse_asm( int num )
{
    int result;
    asm volatile
    // asm: g++ assembly syntax
    // volatile: (C++ keyword) eliminate optimization
    (
        ".intel_syntax   ;\n" // tell g++ to use Intel style instead of the default AT&T style
    // ===== add your codes here =====
        " mov   eax, %1  ;\n" // register eax = num;
        " mov   ebx, 10  ;\n" // register ebx = 10;
        " mov   ecx, 0   ;\n" // register ecx = 0;
  "SHIFT: mov   edx, 0   ;\n" // register edx = 0;
        "idiv   ebx      ;\n" // register eax /= 10; register edx %= 10;
        " add   ecx, edx ;\n" // register ecx += register edx;
        " cmp   eax, 0   ;\n" // compare register eax with 0
        " je    END      ;\n" // if (register eax = 0) goto END;
        " imul  ecx, ebx ;\n" // register ecx *= 10;
        " cmp   eax, 0   ;\n" // compare register eax with 0
        " jne   SHIFT      ;\n" // if (register eax != 0) goto SHIFT;
    "END: mov    %0, ecx ;\n" // result = register eax;
    // =====---------------------=====
        ".att_syntax     ;\n"  // return to AT&T style to pass variables
        : "=r" (result)  // output operands
        : "r" (num)  // input operands
        : "%eax","%ebx","%ecx","%edx" // register used
    );
    return result ;
}
int reverse_cpp( int num ){
    int result = 0;
    int length = 0;

    int stack[10];
    int stackCounter = 0;

    for(int rem=num;rem>0;++length){
        stack[stackCounter++] = rem%10; // you can view this as push
        rem /= 10;
    }

    int shift = 1;
    for(int i=0;i<length;++i){
        result += shift*stack[--stackCounter]; // you can view this as pop
        shift *= 10;
    }

    return result ;
}

#define CASENUM 1000000
#define NUM 0
void evaluate(){
    int* golden = new int[CASENUM];
    int* ans    = new int[CASENUM];
    double cpp_time,asm_time;
    clock_t start;
    //===== run asm function  =====
    start = clock();
    for(int i=0,numA=NUM;i<CASENUM;++i,++numA){
        ans[i]=reverse_asm(numA);
    }
    asm_time = double(clock()-start)/CLOCKS_PER_SEC;
    //===== run cpp function =====
    start = clock();
    for(int i=0,numA=NUM;i<CASENUM;++i,++numA){
        golden[i]=reverse_cpp(numA);
    }
    cpp_time = double(clock()-start)/CLOCKS_PER_SEC;
    //===== checking =====
    int error = 0;
    for(int i=0;i<CASENUM;++i){
        if(ans[i]!=golden[i]) ++error;
        if(ans[i]!=golden[i] && error==1) printf("first error at %d: %d(cpp)!=%d(asm)\n",i,golden[i],ans[i]);
    }
    if(error==0){
        if(asm_time<cpp_time) printf("Congratulation!!, you pass the bonus work ^_^ \n");
        else printf("You pass the basic problem, it's near the bonus requirement >w< \n");
    }else printf("there are %d error(s) T^T \n",error);


    printf("cpp_time = %f sec for %d times\n",cpp_time,CASENUM);
    printf("asm_time = %f sec for %d times\n",asm_time,CASENUM);

    delete [] ans;
    delete [] golden;
}

int main()
{
    //int num = 123456;
    //printf("result: %d\n",reverse_asm(num));
    //printf("result: %d\n",reverse_cpp(num));

    evaluate();

    return 0;
}
