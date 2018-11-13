const Alexa = require('ask-sdk');

const LaunchRequestHandler = {
  canHandle(handlerInput) {
    const request = handlerInput.requestEnvelope.request;
    return request.type === 'LaunchRequest'
  },
  handle(handlerInput) {
     console.log("entro");
    
    return handlerInput.responseBuilder
      .speak('¡Hola!... '+HELP_MESSAGE)
      .reprompt(HELP_REPROMPT)
      .getResponse();
  },
};

const DatoUniversidadHandler = {
  canHandle(handlerInput) {
    const request = handlerInput.requestEnvelope.request;
    return request.type === 'IntentRequest'
        && request.intent.name === 'DatoCuriosoIntent';
  },
  handle(handlerInput) {
    const factArr = data;
    const factIndex = Math.floor(Math.random() * factArr.length);
    const randomFact = factArr[factIndex];
    const speechOutput = GET_FACT_MESSAGE + randomFact;

    return handlerInput.responseBuilder
      .speak(speechOutput)
      .withSimpleCard(SKILL_NAME, randomFact)
       .reprompt("Como te puedo ayudar!")
      .getResponse();
  },
};

const SaludaHandler = {
  canHandle(handlerInput) {
    const request = handlerInput.requestEnvelope.request;
    return request.type === 'IntentRequest'
        && request.intent.name === 'SaludaIntent';
  },
  handle(handlerInput) {
    const request = handlerInput.requestEnvelope.request;
    var nombre = request.intent.slots.nombre.value;
    var speechOutput = "Hola " + nombre;

    return handlerInput.responseBuilder
      .speak(speechOutput)
      .withSimpleCard(SKILL_NAME, speechOutput)
      .reprompt("Como te puedo ayudar!")
      .getResponse();
  },
};

const PorroHandler = {
  canHandle(handlerInput) {
    const request = handlerInput.requestEnvelope.request;
    return request.type === 'IntentRequest'
        && request.intent.name === 'PorroIntent';
  },
  handle(handlerInput) {
    const factArr = quienPorro;
    const factIndex = Math.floor(Math.random() * factArr.length);
    const randomFact = factArr[factIndex];
    const speechOutput = 'Le toca a ' + randomFact;

    return handlerInput.responseBuilder
      .speak(speechOutput)
      .withSimpleCard(SKILL_NAME, speechOutput)
      .reprompt("Como te puedo ayudar!")
      .getResponse();
  },
};



const HelpHandler = {
  canHandle(handlerInput) {
    const request = handlerInput.requestEnvelope.request;
    return request.type === 'IntentRequest'
      && request.intent.name === 'AMAZON.HelpIntent';
  },
  handle(handlerInput) {
    return handlerInput.responseBuilder
      .speak(HELP_MESSAGE)
      .reprompt(HELP_REPROMPT)
      .getResponse();
  },
};

const ExitHandler = {
  canHandle(handlerInput) {
    const request = handlerInput.requestEnvelope.request;
    return request.type === 'IntentRequest'
      && (request.intent.name === 'AMAZON.CancelIntent'
        || request.intent.name === 'AMAZON.StopIntent');
  },
  handle(handlerInput) {
    return handlerInput.responseBuilder
      .speak(STOP_MESSAGE)
      .getResponse();
  },
};

const SessionEndedRequestHandler = {
  canHandle(handlerInput) {
    const request = handlerInput.requestEnvelope.request;
    return request.type === 'SessionEndedRequest';
  },
  handle(handlerInput) {
    console.log(`Se ha terminado la sesión por las siguientes causas: ${handlerInput.requestEnvelope.request.reason}`);

    return handlerInput.responseBuilder.getResponse();
  },
};

const ErrorHandler = {
  canHandle() {
    return true;
  },
  handle(handlerInput, error) {
    console.log(`Error handled: ${error.message}`);

    return handlerInput.responseBuilder
      .speak('<say-as interpret-as="interjection">épale ocurrió un error</say-as>')
      .reprompt('Lo siento, ocurrió un error')
      .getResponse();
  },
};

const SKILL_NAME = 'Volcan';
const GET_FACT_MESSAGE = '';
const HELP_MESSAGE = 'Alexa ve todo lo que pasa en el volcan  y le reporto a mi amo Daniel';
const HELP_REPROMPT = '¿Cómo te puedo ayudar?';
const STOP_MESSAGE = 'Adios y cuida del volcan <say-as interpret-as="interjection">Recureda limpiar</say-as>';

const data = [
  //TODO agrega tu contenido de datos curiososo aqui... 
  'El pipica ha dormido 18 veces en el volcan',
  'Shapiro tiene una adicción al fortnite',
  'Tom brady alias la cabra es la ver ga',
  'El ultimo en decir safo arma un porro',
];

const quienPorro = [
  //TODO agrega tu contenido de datos curiososo aqui... 
  'Pipica',
  'Shapiro',
  'Moy',
  'Ron',
  'Pablito',
  'Ñañel'
];


const skillBuilder = Alexa.SkillBuilders.standard();

exports.handler = skillBuilder
  .addRequestHandlers(
    LaunchRequestHandler,
    SaludaHandler,
    PorroHandler,
    DatoUniversidadHandler,
    HelpHandler,
    ExitHandler,
    SessionEndedRequestHandler,
   
    
  )
  .addErrorHandlers(ErrorHandler)
  .lambda();
