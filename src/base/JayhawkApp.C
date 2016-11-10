#include "JayhawkApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<JayhawkApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

JayhawkApp::JayhawkApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  JayhawkApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  JayhawkApp::associateSyntax(_syntax, _action_factory);
}

JayhawkApp::~JayhawkApp()
{
}

// External entry point for dynamic application loading
extern "C" void JayhawkApp__registerApps() { JayhawkApp::registerApps(); }
void
JayhawkApp::registerApps()
{
  registerApp(JayhawkApp);
}

// External entry point for dynamic object registration
extern "C" void JayhawkApp__registerObjects(Factory & factory) { JayhawkApp::registerObjects(factory); }
void
JayhawkApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void JayhawkApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { JayhawkApp::associateSyntax(syntax, action_factory); }
void
JayhawkApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
