/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "my_rpc.h"

bool_t
xdr_nametype (XDR *xdrs, nametype *objp)
{
	register int32_t *buf;

	 if (!xdr_string (xdrs, objp, MAXNAMELEN))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_namelist (XDR *xdrs, namelist *objp)
{
	register int32_t *buf;

	 if (!xdr_pointer (xdrs, (char **)objp, sizeof (struct namenode), (xdrproc_t) xdr_namenode))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_namenode (XDR *xdrs, namenode *objp)
{
	register int32_t *buf;

	 if (!xdr_nametype (xdrs, &objp->name))
		 return FALSE;
	 if (!xdr_namelist (xdrs, &objp->next))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_readdir_res (XDR *xdrs, readdir_res *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->errno))
		 return FALSE;
	switch (objp->errno) {
	case 0:
		 if (!xdr_namelist (xdrs, &objp->readdir_res_u.list))
			 return FALSE;
		break;
	default:
		break;
	}
	return TRUE;
}

bool_t
xdr_intlist (XDR *xdrs, intlist *objp)
{
	register int32_t *buf;

	 if (!xdr_pointer (xdrs, (char **)objp, sizeof (struct intnode), (xdrproc_t) xdr_intnode))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_intnode (XDR *xdrs, intnode *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->v))
		 return FALSE;
	 if (!xdr_intlist (xdrs, &objp->next))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_coupled_int_list (XDR *xdrs, coupled_int_list *objp)
{
	register int32_t *buf;

	 if (!xdr_intlist (xdrs, &objp->a))
		 return FALSE;
	 if (!xdr_intlist (xdrs, &objp->b))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_coupled_matrix (XDR *xdrs, coupled_matrix *objp)
{
	register int32_t *buf;

	 if (!xdr_array (xdrs, (char **)&objp->a.a_val, (u_int *) &objp->a.a_len, ~0,
		sizeof (int), (xdrproc_t) xdr_int))
		 return FALSE;
	 if (!xdr_array (xdrs, (char **)&objp->b.b_val, (u_int *) &objp->b.b_len, ~0,
		sizeof (int), (xdrproc_t) xdr_int))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->d1))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->d2))
		 return FALSE;
	return TRUE;
}
