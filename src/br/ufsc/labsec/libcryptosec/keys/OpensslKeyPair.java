package br.ufsc.labsec.libcryptosec.keys;

import br.ufsc.labsec.libcryptosec.engine.OpensslDynamicEngine;
import br.ufsc.labsec.libcryptosec.jni.JniObject;

public class OpensslKeyPair extends JniObject {
	
	private native int _init(int engineReference, String keyId);
	private native void _delete();
	private native int _getPublicKey();
	private native int _getPrivateKey();
	
	public OpensslKeyPair(OpensslDynamicEngine engine, String keyId)
	{
		this.reference = _init(engine.getReference(), keyId);
	}
	
	public OpensslPrivateKey getPrivateKey()
	{
		return new OpensslPrivateKey(_getPrivateKey());
	}
	
	public OpensslPublicKey getPublicKey()
	{
		return new OpensslPublicKey(_getPublicKey());
	}
	@Override
	public void delete() {
		_delete();
	}
}
