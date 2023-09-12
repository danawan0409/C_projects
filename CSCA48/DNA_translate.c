////////////////////////////////////////////////////////////
// CSC A48 - DNA alignment Pt. 1
//
// The goal of this assignment is to write a function that
// translates tripled (sets of 3) DNA nucleotide bases to
// the corresponding aminoacid.
//
// As a brief review of your Biology lessons, DNA is a double
// stranded chain of nucleic-acids, there are 4 types of
// nucleotides denoted by the letters:
//
// A, C, T, G
//
// The sequence of these nucleotides specifies the sequence
// in which aminoacids (the building blocks of proteins)
// are assembled into every single one of the proteins that
// make up the cells of most licing things (there are a 
// few that do not use DNA, opting instead to use the single
// stranded version called RNA, viruses tend to be sneaky
// that way!)
//
// Each set of 3 nucleotides specifies one aminoacid in
// a protein's specification.
//
// The goal of this exercise is for you to write a small
// function that takes in a DNA sequence (a string made up
// of letters ATCG in some sequence) and determines the
// corresponding sequence of aminoacids. Below, you will
// find a table listing each aminoacid, and the sequences
// of DNA nucleotides that specify that aminoacid.
// 
// Note that many aminoacids can be specified by more than
// one triplet!
//
//  Aminoacid   Single letter name	Triplets
//  Isoleucine 		"I,	ATT, ATC, ATA"
//  Leucine 		"L, CTT, CTC, CTA, CTG, TTA, TTG"
//  Valine 		"V, GTT, GTC, GTA, GTG"
//  Phenylalanine 	"F, TTT, TTC"
//  Methionine 		"M, ATG"
//  Cysteine 		"C, TGT, TGC"
//  Alanine 		"A, GCT, GCC, GCA, GCG"
//  Glycine 		"G, GGT, GGC, GGA, GGG"
//  Proline 		"P, CCT, CCC, CCA, CCG"
//  Threonine 		"T, ACT, ACC, ACA, ACG"
//  Serine 		"S, TCT, TCC, TCA, TCG, AGT, AGC"
//  Tyrosine 		"Y, TAT, TAC"
//  Tryptophan 		"W, TGG"
//  Glutamine 		"Q, CAA, CAG"
//  Asparagine 		"N, AAT, AAC"
//  Histidine 		"H, CAT, CAC"
//  Glutamic acid 	"E, GAA, GAG"
//  Aspartic acid 	"D, GAT, GAC"
//  Lysine 		"K, AAA, AAG"
//  Arginine 		"R, CGT, CGC, CGA, CGG, AGA, AGG"
//
//  Your task is to determine whether two DNA sequences use the
//  same number of each type of aminoacid (the order of the
//  amino-acids doesn't matter here).
//  To that end, you need to write a function that
//  takes a DNA sequence and converts it to the corresponding
//  sequence of aminoacids, for instance if the input sequence is:
//
//  AAGGAGTGTTTT
//
//  Your function must return
//
//  KECF
//
//  Then you need to write a function that takes in two DNA
//  sequences and determines whether they produce the same
//  numbers of each aminoacid. For example, if the sequence
//  of aminoacids for each of the input DNA sequences is
//
//  AATVKFAA    and    TAAVKAAF
//
//  The function must return 1 (they produce the same number
//  of each aminoacid). However, if the aminoacid sequences
//  are
//
//  TVFAAKVV    and    ECVAATFK
//
//  the function will return 0 (not the same number of each
//  aminoacid).
//
// (c) F. Estrada, March, 2022
///////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void DNA_sequencing(char inputDNA[1024], char outputAminoAcids[1024])
{
    // This function receives two strings, one that contains a sequence
    // of DNA nucleotides (which MUST be composed of the letters
    // ACGT, no spaces or other symbols can appear here!), and
    // updates an initially empty string 'outputAminoAcids' with the
    // sequence of aminoacids corresponding to the input DNA sequence
    //
    // Try to make this function as compact (fewer lines of code, more
    // elegant, easier to read code) as possible. Apply what you've
    // learned in Exercises 6-8, all of which helped you practice
    // using strings!

    // To Do:
    // Complete this function
	for (int i=0;i<strlen(outputAminoAcids);i++){
		outputAminoAcids[i] = 0;
	}
	
	char aa_list[21][1024] = {"I, ATT, ATC, ATA", "L, CTT, CTC, CTA, CTG, TTA, TTG", "V, GTT, GTC, GTA, GTG", "F, TTT, TTC", "M, ATG", 
								"C, TGT, TGC", "A, GCT, GCC, GCA, GCG", "G, GGT, GGC, GGA, GGG", "P, CCT, CCC, CCA, CCG", "T, ACT, ACC, ACA, ACG", 
								"S, TCT, TCC, TCA, TCG, AGT, AGC", "Y, TAT, TAC", "W, TGG", "Q, CAA, CAG", "N, AAT, AAC", "H, CAT, CAC", "E, GAA, GAG",
								"D, GAT, GAC", "K, AAA, AAG", "R, CGT, CGC, CGA, CGG, AGA, AGG"}; 
	char aminoacid[4]; 
	for (int i = 0; i < strlen(inputDNA); i = i + 3){
		aminoacid[0] = inputDNA[i];
		aminoacid[1] = inputDNA[i+1];
		aminoacid[2] = inputDNA[i+2];
		for (int j = 0; j < 21; j = j + 1){
			if (strstr(aa_list[j], aminoacid) != NULL){
				char letter;
				letter = aa_list[j][0];
				//printf("%c\n", letter); 
				strncat(outputAminoAcids, &letter, 1); 
				break; 
			}
		}
	}
}

void sort_string(char inputDNA[1024]){
	char temp;

    int n = strlen(inputDNA);

    for (int i = 0; i < n-1; i++){
		for (int j = i+1; j < n; j++){
			if (inputDNA[i] > inputDNA[j]){
				temp = inputDNA[i];
				inputDNA[i] = inputDNA[j];
				inputDNA[j] = temp;
			}
		}
	}
}

int amino_matching(char inputDNA1[1024], char inputDNA2[1024])
{
    // This function receives two strings representing DNA
    // sequences. It returns 1 if the sequences produce the
    // same number of each type of aminoacid. Think carefully
    // about the best (simplest?) way to to this.

    // To Do:
    // Complete this function
	sort_string(inputDNA1); 
	sort_string(inputDNA2); 
	
	if (strcmp(inputDNA1, inputDNA2) == 0){
		return 1; 
	}
	
    return 0;
}

#ifndef __testing

int main()
{
	char DNAseq1[1024]="CTTATTGTTCCAATGTGGCGGCACTACACGTGCGTTATC";
	char DNAseq2[1024]="ATTTATTGTACATATCATCGTTGGATGCCCGTAATATTG";
        char DNAseq3[1024]="ATCGTTTGCACGTACCACCGGTGGATGCCAGTTATTCTT";
	char aminoAcids[1024]="";

	printf("Input DNA sequence 1: %s\n",DNAseq1);
	DNA_sequencing(DNAseq1,aminoAcids);
	printf("Output aminoacid sequence 1: %s\n",aminoAcids);

	printf("Input DNA sequence 2: %s\n",DNAseq2);
	DNA_sequencing(DNAseq2,aminoAcids);
	printf("Output aminoacid sequence 2: %s\n",aminoAcids);

	printf("Input DNA sequence 3: %s\n",DNAseq3);
	DNA_sequencing(DNAseq3,aminoAcids);
	printf("Output aminoacid sequence 3: %s\n",aminoAcids);

	if (amino_matching(DNAseq1,DNAseq2)==1)
	{
		printf("Sequence 1 matches sequence 2 in aminoacids\n");
	}
	else
	{
		printf("Sequence 1 does not match sequence 2 in aminoacids\n");
	}

	if (amino_matching(DNAseq1,DNAseq3)==1)
	{
		printf("Sequence 1 matches sequence 3 in aminoacids\n");
	}
	else
	{
		printf("Sequence 1 does not match sequence 3 in aminoacids\n");
	}

	if (amino_matching(DNAseq2,DNAseq3)==1)
	{
		printf("Sequence 2 matches sequence 3 in aminoacids\n");
	}
	else
	{
		printf("Sequence 2 does not match sequence 3 in aminoacids\n");
	}

	return 0;
}

#endif
