# legacy project

## What

Introduction and code beloning to my podcast about legacy software.

URL will folow

Examples are spread out in multiple branches

Builds are al created under ubuntu

## How this tutarial is structured

We use the following structure in all projects:


  + [src](src/reedme.md): directory containing sources

  + [doc](doc/README.md): documentation

  + [install_dependencies_ubuntu.sh](install_dependencies_ubuntu.sh): dependencies for ubuntu
  
  + [build.sh](build.sh): Basic build script

  + [run.sh](run.sh): Run what is build
   
  + README.md basic readme file gives more information about this branch


## About legacy software

What is legacy software

- Create by everybody

- Keep code clean

- Try to upgade

- Cost of legacy software (find developers, minor user experience)

## Story line

Company "Hello World Inc" is created by Mr James Hello and Martin World.

Make a lot of money selling hello world applications to companies everywhere.

### Branch LEGACY/VERSION-0.0.0 

1980: the original version of the hello world application.

not getting a lot of response until article in the newspaper that compnaies with hello world made a lot more revenue.

1981: hello world is getting global 20% of companies are using it.

1982: CEO Decided to fire developer, got famous by making articles about self-maintaining software.

Price goes down, 50% of comanies use it.

1983: 70% 

1984: 85%

1985: 95%

1986: Eduardo Las Puertas owner of gigasoft decided to add Hello world to it's operation system.

Number of companies go back to 85%.

1987: Article about differences between gigasoft version and our hello world. Gigasoft has mutli language support

Number of companies go back to 30%.

We start looking for a new developer.

1988: No developer found, only 20% of comanies use this software

### Branch LEGACY/VERSION-1.0.0

1989: Decided to merge to a c application, to get more developers.

We found a software architect, a senior programmer and a junior programmer.

The junior programmer created this version.

### Branch LEGACY/VERSION-1.0.1

Software architect wants to devide the responsibility of the different funcions better, senior software developer implements it.

### Branch LEGACY/VERSION-1.0.2

Junior developer does not dare to change senior developers work. But tries to simplify it.

1990: 15% of the companies use it

### Branch  LEGACY/VERSION-1.1.0

1991: Introduction of custom languages

New marketing model. 20% of companies use our software.

Between 1991 and 1997 70% of companies use this new version.

### Branch LEGACY/VERSION-1.2.0

1998: We needed a webversion. added web support to the existing software

### Branch LEGACY/VERSION-1.2.1

2000: Html version of the software

... Html keeps on evolving, eventualy you end up with maintaining this code.

Show some complex pictures with ngix etc ...

Suddendly they ask you to create a microservice based on hello world app

What do you do, what are te counteractions ...

# General installation instructions

## Installing needed dependencies in ubuntu

```bash
./install_dependencies_ubuntu.sh
```

## Building this code


```bash
./build.sh
```

## Running this code

```bash
./run.sh
```

