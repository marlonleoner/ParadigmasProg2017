# T8: Gerador de Formulários em C++

  - Para o desenvolvimento do programa foi utilizado C++ e a biblioteca FLTK

## Compilação e Execução

- Para compilação utilize o makefile, ele conta com as seguintes opções:
  - make (compilação);
  - make clean (remove os arquivos criados);
  - make run (executa a aplicação).

## Arquivos de Projeto

- Os arquivos de projeto possuem a extensão **.csv**;
- Os arquivos são salvos na pasta `project/`
- Modelo de um projeto:
  - 1ª linha - Title da página;
  - Demais linhas - Inputs
- As linhas com inputs possuem a seguinte configuração:
  - Text: text;[Input ID];[Input Label]
  - Select: select;[Input ID];[Input Label];[Op1];[Op2];[Op3];[...];[OpN]
  - Radio: radio;[Input ID];[Input Label];[Op1];[Op2];[Op3];[...];[OpN]

- Example.csv:
  > Example <br/>
  text;TextExampleID;Text Example <br/>
  select;SelectExampleID;Select Example;Op1;Op2;Op3;Op4;Op5 <br/>
  radio;RadioExampleID;Radio Example;Op1;Op2;Op3;Op4;Op5 <br/>
  
- O arquivo `index.html` é gerado na pasta `HTML/`
