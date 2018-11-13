/* eslint-disable  func-names */
/* eslint-disable  no-console */

const Alexa = require('ask-sdk');

const UnVoladoHandler = {
  canHandle(handlerInput) {
    const request = handlerInput.requestEnvelope.request;
    return request.type === 'LaunchRequest'
  },
  handle(handlerInput) {
    var result = Math.floor(Math.random() * 2);
    var speechOutput = "Águila";
    var card = "Águila";
    var imageName = "aguila.jpeg";
    
    console.log(`result=`+result);
    if ( result == 1 ){
       card = "Sol";
       speechOutput = "Sol";
       imageName = "sello.jpeg"
    }
    
    speechOutput ='<audio src="'+AUDIO_LINK+'"/>'+speechOutput;
    console.log('speechOutput->' + speechOutput);
    
    return handlerInput.responseBuilder
      .withStandardCard(SKILL_NAME, card, CONTENT_URL+imageName,CONTENT_URL+imageName)
      .speak(speechOutput)
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
    console.log(`Session ended with reason: ${handlerInput.requestEnvelope.request.reason}`);

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
      .speak('<say-as interpret-as="interjection">híjole</say-as> ...ocurrió un error, lo siento, intenta de nuevo')
      .getResponse();
  },
};

const SKILL_NAME = 'Volado';
const STOP_MESSAGE = '<say-as interpret-as="interjection">ahí nos vemos</say-as>';
const AUDIO_LINK = 'https://s3.amazonaws.com/alexa-mx-sounds/volado.mp3';
const CONTENT_URL = 'https://s3.amazonaws.com/alexa-mx-sounds/';

const skillBuilder = Alexa.SkillBuilders.standard();

exports.handler = skillBuilder
  .addRequestHandlers(
    UnVoladoHandler,
    ExitHandler,
    SessionEndedRequestHandler
  )
  .addErrorHandlers(ErrorHandler)
  .lambda();
