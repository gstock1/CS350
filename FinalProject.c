
#include <stdio.h>
#include <stdlib.h> // For error exit()

typedef unsigned char byte;
struct R_Format {byte rs, rt, rd, shamt, funct;};
struct I_Format {byte rs, rt; short immediate;};
struct J_Format {unsigned int address;};

struct instruction {
        byte opcode;
        union {
                struct R_Format r_form;
                struct I_Format i_form;
                struct J_Format j_form;
        };
};

int operation(unsigned char instruction){ //method for printing registers
        switch (instruction){
                            case 0: printf("\t$0,");
                                    break;
                            case 1: printf("\t$at,");
                                    break;
                            case 2: printf("\t$v0,");
                                    break;
                            case 3: printf("\t$v1,");
                                    break;
                            case 4: printf("\t$a0,");
                                    break;
                            case 5: printf("\t$a1,");
                                    break;
                            case 6: printf("\t$a2,");
                                    break;
                            case 7: printf("\t$a3,");
                                    break;
                            case 8: printf("\t$t0,");
                                    break;
                            case 9: printf("\t$t1,");
                                    break;
                            case 10: printf("\t$t2,");
                                    break;
                            case 11: printf("\t$t3,");
                                    break;
                             case 12: printf("\t$t4,");
                                    break;
                             case 13: printf("\t$t5,");
                                    break;
                             case 14: printf("\t$t6,");
                                    break;
                             case 15: printf("\t$t7,");
                                    break;
                             case 16: printf("\t$s0,");
                                    break;
                             case 17: printf("\t$s1,");
                                    break;
                             case 18: printf("\t$s2,");
                                    break;
                             case 19: printf("\t$s3,");
                                    break;
                             case 20: printf("\t$s4,");
                                    break;
                             case 21: printf("\t$s5,");
                                    break;
                             case 22: printf("\t$s6,");
                                    break;
                             case 23: printf("\t$s7,");
                                    break;
                             case 24: printf("\t$t8,");
                                    break;
                             case 25: printf("\t$t9,");
                                    break;
                             case 26: printf("\t$k0,");
                                    break;
                             case 27: printf("\t$k1,");
                                    break;
                             case 28: printf("\t$gp,");
                                    break;
                             case 29: printf("\t$sp,");
                                    break;
                             case 30: printf("\t$fp,");
                                    break;
                             case 31: printf("\t$ra,");
                                    break;
                    }
}
int main(void) {
    printf("George Stock -- Final Project\n");
    int count = 0;
    char *datafile_name = "data.txt";
    FILE *datafile = fopen(datafile_name, "r");
    printf("Loading %s\n", datafile_name);

    struct instruction data[27];
    unsigned int hex[100];
 //read hex instructions into an array from the file
    for(int i =0; i<30; i++){
            if(!datafile){
            printf("; open failed; program ends\n");
                    exit(EXIT_FAILURE);
            }
            else{

            unsigned int x;
            fscanf(datafile, "%x", &x);
            hex[i] = x;
            }
    }

    fclose(datafile);
    for(int i =0; i<27; i++){ //step through the array of hex instructions and find the opcodes
        unsigned int instruction32bit = hex[i];
        unsigned int mask = 0x0000003F;
        unsigned int opcode = (instruction32bit>>26) & mask;
        if(opcode == 0){  //depending on the opcode, splits 32 bit string into Struct
                data[i].opcode = opcode;
                unsigned int registerMask = 0x1f;
                unsigned int functMask = 0x3f;
                data[i].r_form.rs = (instruction32bit>>21)&registerMask;
                data[i].r_form.rt = (instruction32bit>>16)&registerMask;
                data[i].r_form.rd = (instruction32bit>>11)&registerMask;
                data[i].r_form.shamt = (instruction32bit>>6)&registerMask;
                data[i].r_form.funct = instruction32bit&functMask;
        }
        else if (opcode == 2 || opcode == 3){
                data[i].opcode = opcode;
                unsigned int ADDmask = 0x3ffffff;
                data[i].j_form.address = instruction32bit&ADDmask;
        }
        else if (opcode == 4 || opcode == 5){
                unsigned int registerMask = 0x1f;
                signed int immMask = 0xffff;
                data[i].opcode = opcode;
                data[i].i_form.rs = (instruction32bit>>21)&registerMask;
                data[i].i_form.rt = (instruction32bit>>16)&registerMask;
                data[i].i_form.immediate = instruction32bit&immMask;
        }
        else {
                data[i].opcode = opcode;
                unsigned int registerMask = 0x1f;
                unsigned int immMask = 0xffff;
                data[i].i_form.rs = (instruction32bit>>21)&registerMask;
                data[i].i_form.rt = (instruction32bit>>16)&registerMask;
                data[i].i_form.immediate = instruction32bit&immMask;
        }
    }
    printf("Enter program counter (hex digits): ");
    unsigned int address;
    scanf("%x", &address);
    printf("\n\nInitial Program Counter = x%x\n\n", address);
    printf("Location\tInstruction\n");
    for(int i = 0; i<27; i++){//prints instructions
            unsigned int currentI = i + i + i + i;
            unsigned int currentAddress = address + currentI;
            printf("x%x",currentAddress);
            if(data[i].opcode == 0){

                    switch (data[i].r_form.funct){
                            case 32: printf("\tadd");
                                     break;
                            case 34: printf("\tsub");
                                     break;
                            case 36: printf("\tand");
                                     break;
                            case 37: printf("\tor");
                                     break;
                            case 39: printf("\tnor");
                                     break;
                            case 42: printf("\tslt");
                                     break;
                            case 8: printf("\tjr");
                                    break;
                            case 24: printf("\tmul");
                                     break;
                            case 26: printf("\tdiv");
                                     break;
                            case 40: printf("\txor");
                                     break;
                    }
                    if(data[i].r_form.funct == 0){
                            if(data[i].r_form.shamt == 0){
                                    printf("\tnop");
                            }
                            else{
                                    printf("\tsll");
                            }
                    }
                        operation(data[i].r_form.rs);
                        operation(data[i].r_form.rt);
                        operation(data[i].r_form.rd);
                        printf("\t%x\n", data[i].r_form.shamt);

            }
            else if(data[i].opcode == 2){
                    printf("\tj\tx%x\n",data[i].j_form.address);
            }
            else if(data[i].opcode == 3){
                    printf("\tjal\tx%x\n",data[i].j_form.address);
            }
            else{
                    switch(data[i].opcode){
                            case 4: printf("\tbeq");
                                break;
                            case 5: printf("\tbne");
                                    break;
                            case 8: printf("\taddi");
                                    break;
                            case 10: printf("\tslti");
                                     break;
                            case 12: printf("\tandi");
                                    break;
                            case 13: printf("\tori");
                                    break;
                            case 15: printf("\tlui");
                                    break;
                            case 35: printf("\tlw");
                                    break;
                            case 43: printf("\tsw");
                                    break;
                            case 14: printf("\txori");
                                     break;
                }
                    operation(data[i].i_form.rs);
                    operation(data[i].i_form.rt);
                    unsigned int immediateMask = 0xffff;
                    signed int currentImmediate =  data[i].i_form.immediate&immediateMask;

                    printf("\tx%04x", currentImmediate);
                    if(data[i].opcode == 4 || data[i].opcode == 5){
                            signed int target = data[i].i_form.immediate + currentAddress;
                            printf("\t(dec %d, target = x%x)\n",data[i].i_form.immediate, target);
                    }
                    else{
                            printf("(dec %d)\n",data[i].i_form.immediate);
                    }

            }


    }
    printf("\nProgram terminated.\n");
}