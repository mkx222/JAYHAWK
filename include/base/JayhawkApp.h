#ifndef JAYHAWKAPP_H
#define JAYHAWKAPP_H

#include "MooseApp.h"

class JayhawkApp;

template<>
InputParameters validParams<JayhawkApp>();

class JayhawkApp : public MooseApp
{
public:
  JayhawkApp(InputParameters parameters);
  virtual ~JayhawkApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* JAYHAWKAPP_H */
