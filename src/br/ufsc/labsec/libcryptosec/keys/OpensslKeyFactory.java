package br.ufsc.labsec.libcryptosec.keys;

import br.ufsc.labsec.libcryptosec.engine.OpensslDynamicEngine;
import br.ufsc.labsec.libcryptosec.engine.OpensslEngineCommand;
import br.ufsc.labsec.libcryptosec.exceptions.EngineException;
import br.ufsc.labsec.libcryptosec.jni.JniObject;

public class OpensslKeyFactory {

	static OpensslKeyFactory instanece = null;
	
	private OpensslDynamicEngine engine;
	
	private OpensslKeyFactory(String enginePath, String engineId, OpensslEngineCommand[] commands) throws EngineException
	{
		
		this.engine = new OpensslDynamicEngine(enginePath, engineId, commands);
		
	}

	/*
	 * TODO verificar como fica para acesso concorrente
	 */
	static public OpensslKeyFactory getInstance(String enginePath, String engineId, OpensslEngineCommand[] commands)  throws EngineException
	{
		if(instanece == null)
			instanece = new OpensslKeyFactory(enginePath, engineId, commands);
		
		return instanece;
	}
	
	public OpensslKeyPair getKeyPair(String keyId)
	{
		return new OpensslKeyPair(this.engine, keyId);
	}

}