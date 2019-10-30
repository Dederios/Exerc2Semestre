# Exerc2Semestre
Exercícios do segundo semestre de Análise e Desenvolvimento de Sistemas - Disciplina: TecProg II.

Exercício 1: Elabore um algoritmo em C para ler dez elementos numéricos em um vetor e imprimir o maior e o menor numero.

Exercício 2: Elabore um algoritmo em C que leia um vetor N(20) e o escreve. Troque, a seguir, o 1º elemento com o último, o 2º com o penúltimo etc. até o 10º com o 11º e escreva o vetor N assim modificado.

Exercício 3: Elabore um algoritmo em C que leia dez conjuntos de dois valores, o primeiro representando o numero do aluno e o segundo representando a sua altura em metros. Encontre o aluno mais baixo e o mais alto. Mostre o numero do aluno mais baixo e do mais alto, juntamente com suas alturas.

Exercício 4: Elabore um programa que permita corrigir as provas dos alunos de uma Instituição de Ensino que elabora as provas com 10 questões. O sistema deverá permitir inserir:
- O Gabarito com dez alternativas de A a E.
- Os nomes dos alunos com seus respectivos cursos e as suas notas de A a E.

E deverá exibir a relação de notas com a mensagemn de “APROVADO” com nota maior ou igual a 5,0 e “REPROVADO” para os demais.

Exercício Gestão Academica: O Programa deverá ter uma tela de apresentação (menu) com as seguintes opções: 
- Cadastro
- Consulta
- Alteração
- Exclusão
- Relatório

Tela de Cadastro: Deverá permitir cadastrar os dados que serão inseridos pelos usuários e ser armazenados nos vetores criados.
- RGM do Aluno (numerico inteiro ou string)
- Nome Completo (string)
- Curso (string)
- N1 (numerico real)
- N2 (numerico real)
- Total de Faltas (numérico inteiro)
- Média Final  (numerico real)

Restrições da tela de cadastro:
- O Campo RGM deve ser iniciado com o ano (19) e os demais dígitos gerados automaticamente.
- O Campo Media deverá ser calculado pela formula: MF=(N1+N2*2)/3
- O campo total de faltas não poderá exceder o limite de 80 aulas semestrais

Tela de Consulta:
- Consulta por RGM
- Consulta por Nome
- Melhor Aluno do Curso
- Consulta por Curso

Tela de Alteração:

-Deve ser fornecido o RA do Aluno e em seguida deve ser exibido o seu conteúdo com um numero indicando o campo a ser alterado.

Tela de Exclusão:

-Deve ser fornecido o RA do Aluno e em seguida deve ser exibido o seu conteudo com uma confirmação de exclusão.

Tela de Relatório:
- Relatório 1: Devem ser listados em forma de relatorio todos os Alunos que estão REPROVADOS.
- Relatorio 2: Deve ser informado o curso e o sistema exibir todos os alunos do curso em ordem alfabética!
